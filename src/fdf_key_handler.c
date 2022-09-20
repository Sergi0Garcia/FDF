/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:53:57 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/20 13:24:18 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	is_valid_key(int key)
{
	return (key == 6 || key == 7 || key == 18 || key == 19 || key == 20
		|| key == 21 || key == 22 || key == 23 || key == 24 || key == 27
		|| key == 34 || key == 53 || key == 123 || key == 124 || key == 125
		|| key == 126 || key == 3 || key == 4 || key == 5 || key == 11);
}

static void	handle_translation(int key, t_fdf *d)
{
	if (key == 123)
		d->shift_x -= 50;
	if (key == 124)
		d->shift_x += 50;
	if (key == 125)
		d->shift_y += 50;
	if (key == 126)
		d->shift_y -= 50;
}

static void	handle_rotation(int key, t_fdf *d)
{
	if (key == 18)
		d->rotation_x -= 0.1;
	if (key == 19)
		d->rotation_x += 0.1;
	if (key == 20)
		d->rotation_y -= 0.1;
	if (key == 21)
		d->rotation_y += 0.1;
	if (key == 22)
		d->rotation_z -= 0.1;
	if (key == 23)
		d->rotation_z += 0.1;
}


static void	handle_mutation(int key, t_fdf *d)
{
	int	val;

	if (key == 6)
		d->z_mult += 0.2;
	if (key == 7)
		d->z_mult -= 0.2;
	if (key == 24)
		d->zoom += 5;
	if (key == 11)
	{
		val = d->is_blur;
		if (val == 1)
			d->is_blur = 0;
		if (val == 0)
			d->is_blur = 1;
	}
	if (key == 27)
	{
		if (d->zoom -2 <= 1)
			d->zoom /= 2;
		else
			d->zoom -= 2;
	}
	if (key == 34)
	{
		val = d->is_isometric;
		if (val == 1)
			d->is_isometric = 0;
		if (val == 0)
			d->is_isometric = 1;
	}
}

int	key_handler(int key, t_fdf *d)
{
	if (is_valid_key(key))
	{
		if (key == 3 || key == 4 || key == 5)
			return (full_size(key, d));
		if (key > 17 && key < 24)
			handle_rotation(key, d);
		else if (key > 122 && key < 127)
			handle_translation(key, d);
		else if (key != 53)
			handle_mutation(key, d);
		else if (key == 53)
		{
			mlx_destroy_window(d->mlx_ptr, d->win_ptr);
			exit(0);
		}
	}
	mlx_clear_window(d->mlx_ptr, d->win_ptr);
	draw(d);
	return (0);
}
