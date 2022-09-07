/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:32:31 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/07 14:45:42 by segarcia         ###   ########.fr       */
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

void	rotation_x(float *x, float *y, int *z, fdf *data)
{
	float ac_x;
	float ac_y;
	float ac_z;
	float test;

	ac_x = *x;
	ac_y = *y;
	ac_z = *z;

	*x = ac_x;
	test = (cos(data->rotation_x) * ac_y) - (sin(data->rotation_x) * ac_z);
	*y = test;
	*z = (sin(data->rotation_x) * ac_y) + (cos(data->rotation_x) * ac_z);
}

void	rotation_y(float *x, float *y, int *z, fdf *data)
{
	float ac_x;
	float ac_y;
	float ac_z;

	ac_x = *x;
	ac_y = *y;
	ac_z = *z;

	*x = (cos(data->rotation_y) * ac_x) + (sin(data->rotation_y) * ac_z);
	*y = ac_y;
	*z = -(sin(data->rotation_y) * ac_x) + (cos(data->rotation_y) * ac_z);
}

void	rotation_z(float *x, float *y, int *z, fdf *data)
{
	float ac_x;
	float ac_y;
	float ac_z;

	ac_x = *x;
	ac_y = *y;
	ac_z = *z;

	*x = (cos(data->rotation_z) * ac_x) - (sin(data->rotation_z) * ac_y);
	*y = (sin(data->rotation_z) * ac_x) + (cos(data->rotation_z) * ac_y);
	*z = ac_z;

}

void	bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;
	int		c;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	c = data->hex_color[(int)y][(int)x];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	// ft_printf("Hexcolor: %i\n", data->hex_color[(int)y][(int)x]);
	// if (data->hex_color[(int)y][(int)x])
	// {
	// 	ft_printf("Hexcolor: %i\n", data->hex_color[(int)y][(int)x]);
	// 	data->color = data->hex_color[(int)y][(int)x];
	// }
	// else
	if (c)
		data->color = c;
	else if (z || z1)
		data->color = 0xFF0000;
	else
		data->color = 0xFFFFFF;
	rotation_x(&x, &y, &z, data);
	rotation_x(&x1, &y1, &z1, data);
	rotation_y(&x, &y, &z, data);
	rotation_y(&x1, &y1, &z1, data);
	rotation_z(&x, &y, &z, data);
	rotation_z(&x1, &y1, &z1, data);
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
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
		// if (x > 1000 || y > 1000 || y < 0 || x < 0)
		// 	break ;
	}
}

// void test(float x, float y, fdf *data)
// {
// 	int z;
// 	int x2d;
// 	int y2d;

// 	x2d = 0.0;
// 	y2d = 0.0;
// 	z = data->z_matrix[(int)y][(int)x];
// 	ft_printf("[%i, %i, %i] --- ", x, y, z);
// 	x2d = ((x * 0.8660 * -1) + (y * 0.8660));
// 	y2d = (x * -0.5) + (y * -0.5) + z;
// 	ft_printf("[%i, %i] \n", x2d, y2d);
// 	mlx_pixel_put(data->mlx_ptr, data->win_ptr, (x2d * data->zoom) + 100, (y2d * data->zoom) - 100, 0xffffff);
// }

void	draw(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			// test((float)x, (float)y, data);
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
