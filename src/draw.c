/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:32:31 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/12 14:38:51 by segarcia         ###   ########.fr       */
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

void	ft_handle_2d(float *x, float *y, fdf_data * data)
{
	ft_zoom(x, y, data);
	translation(x, y, data);
}

void	ft_handle_3d(float *x, float *y, float *z, fdf_data * data)
{
	rotation_xyz(x, y, z, data);
	isometric(x, y, z);
}

void	bresenham(float x, float y, char increment, fdf_data *data)
{
	float	x_step;
	float	y_step;
	int		max;
	float	z;
	float	z1;
	float	x1;
	float 	y1;

	if (increment == 'x')
	{
		x1 = x + 1;
		y1 = y;
	}
	if (increment == 'y')
	{
		x1 = x;
		y1 = y + 1;
	}
	z = (data->z_matrix[(int)y][(int)x]) * data->z_mult;
	z1 = (data->z_matrix[(int)y1][(int)x1]) * data->z_mult;
	define_color(data->hex_color[(int)y][(int)x], z || z1, data);
	ft_handle_2d(&x, &y, data);
	ft_handle_2d(&x1, &y1, data);
	if (data->is_isometric == 1)
	{
		ft_handle_3d(&x, &y, &z, data);
		ft_handle_3d(&x1, &y1, &z1, data);
	}
	x_step = x1 - x;
	y_step = y1 - y;
	max = f_max(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
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
