/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:32:31 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/20 12:22:08 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
# include <stdio.h>

void	increment_handler(t_plane *p)
{
	p->x_step = p->x1 - p->x;
	p->y_step = p->y1 - p->y;
	p->max = f_max(fabs(p->x_step), fabs(p->y_step));
	p->x_step /= p->max;
	p->y_step /= p->max;
}

void	handle_blur(float num, t_fdf *d)
{
	if (num <= 20 || num >= 80)
		d->color = 0xFF0000;
	else
		d->color = 0xFFFFFF;
}

void	define_color(t_plane *p, t_fdf *d)
{
	int color;

	p->is_slope = 0;
	color = d->hex_color[(int)p->y][(int)p->x];
	if (color)
		d->color = color;
	else if ((p->z || p->z1) && (p->z == p->z1))
		d->color = 0xBF40BF;
	else if (d->is_isometric == 0 && (p->z || p->z1))
		d->color = 0xBF40BF;
	else if ((p->z || p->z1) && (p->z != p->z1))
		p->is_slope = 1;
	else
		d->color = 0xFFFFFF;
}

void	handle_slope_blur(t_plane *p, t_fdf *d)
{
	if (p->is_slope)
			p->i_slope++;
	if (p->i_slope)
	{
		if ((p->i_slope/p->max) >= 0.1)
			d->color = 0xff9507;
		if ((p->i_slope/p->max) >= 0.2)
			d->color = 0xffa62e;
		if ((p->i_slope/p->max) >= 0.3)
			d->color = 0xffae42;
		if ((p->i_slope/p->max) >= 0.4)
			d->color = 0xffb656;
		if ((p->i_slope/p->max) >= 0.5)
			d->color = 0xffbf69;
		if ((p->i_slope/p->max) >= 0.6)
			d->color = 0xffc77d;
		if ((p->i_slope/p->max) >= 0.7)
			d->color = 0xffd090;
		if ((p->i_slope/p->max) >= 0.8)
			d->color = 0xffe0b8;
		if ((p->i_slope/p->max) >= 0.9)
			d->color = 0xffe9cb;
		}
}

void	bresenham(float x, float y, char increment, t_fdf *d)
{
	t_plane	*p;

	p = (t_plane *)malloc(sizeof(t_plane));
	handle_plane_error(d, p);
	p->x = x;
	p->y = y;
	plane_setter(p, d, increment);
	define_color(p, d);
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
		handle_slope_blur(p, d);
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
