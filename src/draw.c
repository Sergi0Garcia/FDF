/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:32:31 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/14 11:13:51 by segarcia         ###   ########.fr       */
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

void	bresenham(float x, float y, char increment, fdf_data *data)
{
	point	*plane;
	int		max;
	float	x1;
	float	y1;

	plane = (point *)malloc(sizeof(point));
	if (increment == 'x')
	{
		plane->x1 = x + 1;
		plane->y1 = y;
	}
	if (increment == 'y')
	{
		plane->x1 = x;
		plane->y1 = y + 1;
	}
	x1 = plane->x1;
	y1 = plane->y1;
	ft_printf("x");
	plane->z = (data->z_matrix[(int)y][(int)x]) * data->z_mult;
	ft_printf("x");
	plane->z1 = (data->z_matrix[(int)y1][(int)x1]) * data->z_mult;
	ft_printf("x");
	define_color(data->hex_color[(int)y][(int)x], plane->z || plane->z1, data);
	ft_printf("x");
	if (data->is_isometric == 1)
	{
		ft_handle_3d(&x, &y, &plane->z, data);
		ft_handle_3d(&plane->x1, &plane->y1, &plane->z1, data);
	}
	ft_printf("x");
	ft_handle_2d(&x, &y, data);
	ft_handle_2d(&plane->x1, &plane->y1, data);
	plane->x_step = plane->x1 - x;
	plane->y_step = plane->y1 - y;
	max = f_max(fabs(plane->x_step), fabs(plane->y_step));
	plane->x_step /= max;
	plane->y_step /= max;
	while ((int)(x - plane->x1) || (int)(y - plane->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += plane->x_step;
		y += plane->y_step;
		if (x > data->win_x || y > data->win_y || y < 0 || x < 0)
			break ;
	}
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
