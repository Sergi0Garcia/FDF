/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:32:31 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/20 13:18:32 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	increment_handler(t_line *l)
{
	l->x_step = l->x1 - l->x;
	l->y_step = l->y1 - l->y;
	l->max = f_max(fabs(l->x_step), fabs(l->y_step));
	l->x_step /= l->max;
	l->y_step /= l->max;
}

void	define_color(t_line *l, t_fdf *d)
{
	int	color;

	l->is_slope = 0;
	color = d->hex_color[(int)l->y][(int)l->x];
	if (color)
		d->color = color;
	else if ((l->z || l->z1) && (l->z == l->z1))
		d->color = 0xBF40BF;
	else if (d->is_isometric == 0 && (l->z || l->z1))
		d->color = 0xBF40BF;
	else if ((l->z || l->z1) && (l->z != l->z1) && d->is_blur == 0)
		d->color = 0xBF40BF;
	else if ((l->z || l->z1) && (l->z != l->z1))
		l->is_slope = 1;
	else
		d->color = 0xFFFFFF;
}

void	handle_slope_blur(t_line *l, t_fdf *d)
{
	if (d->is_blur == 0)
		return ;
	if (l->is_slope)
			l->i_slope++;
	if (l->i_slope)
	{
		if ((l->i_slope / l->max) >= 0.1)
			d->color = 0xff9507;
		if ((l->i_slope / l->max) >= 0.2)
			d->color = 0xffa62e;
		if ((l->i_slope / l->max) >= 0.3)
			d->color = 0xffae42;
		if ((l->i_slope / l->max) >= 0.4)
			d->color = 0xffb656;
		if ((l->i_slope / l->max) >= 0.5)
			d->color = 0xffbf69;
		if ((l->i_slope / l->max) >= 0.6)
			d->color = 0xffc77d;
		if ((l->i_slope / l->max) >= 0.7)
			d->color = 0xffd090;
		if ((l->i_slope / l->max) >= 0.8)
			d->color = 0xffe0b8;
		if ((l->i_slope / l->max) >= 0.9)
			d->color = 0xffe9cb;
	}
}

void	bresenham(float x, float y, char increment, t_fdf *d)
{
	t_line	*l;

	l = (t_line *)malloc(sizeof(t_line));
	line_validation(d, l);
	l->x = x;
	l->y = y;
	line_setter(l, d, increment);
	define_color(l, d);
	if (d->is_isometric == 1)
		ft_handle_3d(l, d);
	ft_handle_2d(l, d);
	increment_handler(l);
	while ((int)(l->x - l->x1) || (int)(l->y - l->y1))
	{
		handle_slope_blur(l, d);
		mlx_pixel_put(d->mlx_ptr, d->win_ptr, l->x, l->y, d->color);
		l->x += l->x_step;
		l->y += l->y_step;
		if (l->x > d->win_x || l->y > d->win_y)
			break ;
	}
	free(l);
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
