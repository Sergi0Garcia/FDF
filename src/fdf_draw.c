/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:32:31 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/19 12:32:57 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

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

void	plane_setter(t_plane *p, t_fdf *d, char increment)
{
	if (increment == 'x')
	{
		p->x1 = p->x + 1;
		p->y1 = p->y;
	}
	if (increment == 'y')
	{
		p->x1 = p->x;
		p->y1 = p->y + 1;
	}
	p->z = (d->z_matrix[(int)p->y][(int)p->x]) * d->z_mult;
	p->z1 = (d->z_matrix[(int)p->y1][(int)p->x1]) * d->z_mult;
}

void	increment_handler(t_plane	*p)
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
	t_plane	*p = NULL;

	p = (t_plane *)malloc(sizeof(t_plane));
	if (p == NULL)
	{
		int i;
		i = d->height;
		while(i >= 0)
		{
			free(d->z_matrix[i]);
			free(d->hex_color[i]);
			i--;
		}
		free(d->z_matrix);
		free(d->hex_color);
		malloc_error(d);
	}
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
		mlx_pixel_put(d->mlx_ptr, d->win_ptr, p->x, p->y, 0xFFFFFF);
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
