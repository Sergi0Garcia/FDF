/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:32:31 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/19 13:57:19 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	define_color(int c, float z, float z1, t_fdf *d)
{
	if (c)
		d->color = c;
	else if ((z || z1) && (z == z1))
		d->color = 0xFFFFFF;
	else if ((z || z1) && (z != z1))
		d->color = 0xFFFFFF;
	else
		d->color = 0xFFFFFF;
}

void	increment_handler(t_plane *p)
{
	int	max;

	p->x_step = p->x1 - p->x;
	p->y_step = p->y1 - p->y;
	max = f_max(fabs(p->x_step), fabs(p->y_step));
	p->x_step /= max;
	p->y_step /= max;
}

void	bresenham(float x, float y, char increment, t_fdf *d)
{
	t_plane	*p;

	p = (t_plane *)malloc(sizeof(t_plane));
	handle_plane_error(d, p);
	p->x = x;
	p->y = y;
	plane_setter(p, d, increment);
	define_color(d->hex_color[(int)p->y][(int)p->x], p->z, p->z1, d);
	if (d->is_isometric == 1)
	{
		ft_handle_3d(&p->x, &p->y, &p->z, d);
		ft_handle_3d(&p->x1, &p->y1, &p->z1, d);
	}
	ft_handle_2d(&p->x, &p->y, d);
	ft_handle_2d(&p->x1, &p->y1, d);
	increment_handler(p);
	while ((int)(p->x - p->x1) || (int)(p->y - p->y1))
	{
		mlx_pixel_put(d->mlx_ptr, d->win_ptr, p->x, p->y, d->color);
		p->x += p->x_step;
		p->y += p->y_step;
		if (p->x > d->win_x || p->y > d->win_y)
			break ;
	}
	free(p);
}

void	draw(t_fdf *d)
{
	int	x;
	int	y;

	y = 0;
	fdf_print_menu(d);
	while (y < d->height)
	{
		x = 0;
		while (x < d->width)
		{
			if (x < d->width - 1)
				bresenham(x, y, 'x', d);
			if (y < d->height - 1)
				bresenham(x, y, 'y', d);
			x++;
		}
		y++;
	}
}
