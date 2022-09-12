/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:32:31 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/12 13:39:09 by segarcia         ###   ########.fr       */
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

float	f_mod(float num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	translation(float *x, float *y, fdf_data *data)
{
	*x += data->shift_x;
	*y += data->shift_y;
}

void	bresenham(float x, float y, char increment, fdf_data *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;
	int		c;
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
	c = data->hex_color[(int)y][(int)x];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	if (c)
		data->color = c;
	else if (z || z1)
		data->color = 0xFF0000;
	else
		data->color = 0xFFFFFF;
	if (data->is_isometric == 1)
	{
		rotation(&x, &y, &z, data);
		rotation(&x1, &y1, &z1, data);
		isometric(&x, &y, z);
		isometric(&x1, &y1, z1);
	}
	translation(&x, &y, data);
	translation(&x1, &y1, data);
	x_step = x1 - x;
	y_step = y1 - y;
	max = f_max(f_mod(x_step), f_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
		if (x > 1000 || y > 1000 || y < 0 || x < 0)
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
