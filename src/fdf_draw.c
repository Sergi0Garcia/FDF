/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:32:31 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/14 14:22:27 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	f_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	define_color(int c, int is_z, fdf_data *data)
{
	if (c)
		data->color = c;
	else if (is_z)
		data->color = 0xFF0000;
	else
		data->color = 0xFFFFFF;
}

void	plane_setter(point *plane, fdf_data *data, char increment)
{
	if (increment == 'x')
	{
		plane->x1 = plane->x + 1;
		plane->y1 = plane->y;
	}
	if (increment == 'y')
	{
		plane->x1 = plane->x;
		plane->y1 = plane->y + 1;
	}
	plane->z = (data->z_matrix[(int)plane->y][(int)plane->x]) * data->z_mult;
	plane->z1 = (data->z_matrix[(int)plane->y1][(int)plane->x1]) * data->z_mult;
}

void	increment_handler(point	*plane)
{
	int	max;

	plane->x_step = plane->x1 - plane->x;
	plane->y_step = plane->y1 - plane->y;
	max = f_max(fabs(plane->x_step), fabs(plane->y_step));
	plane->x_step /= max;
	plane->y_step /= max;
}

void	bresenham(float x, float y, char increment, fdf_data *data)
{
	point	*p;

	p = (point *)malloc(sizeof(point));
	p->x = x;
	p->y = y;
	plane_setter(p, data, increment);
	define_color(data->hex_color[(int)p->y][(int)p->x], p->z || p->z1, data);
	if (data->is_isometric == 1)
	{
		ft_handle_3d(&p->x, &p->y, &p->z, data);
		ft_handle_3d(&p->x1, &p->y1, &p->z1, data);
	}
	ft_handle_2d(&p->x, &p->y, data);
	ft_handle_2d(&p->x1, &p->y1, data);
	increment_handler(p);
	while ((int)(p->x - p->x1) || (int)(p->y - p->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, p->x, p->y, data->color);
		p->x += p->x_step;
		p->y += p->y_step;
		if (p->x > data->win_x || p->y > data->win_y || p->y < 0 || p->x < 0)
			break ;
	}
	free(p);
}

void	draw(fdf_data *data)
{
	int	x;
	int	y;

	y = 0;
	fdf_print_menu(data);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, 'x', data);
			if (y < data->height - 1)
				bresenham(x, y, 'y', data);
			x++;
		}
		y++;
	}
}
