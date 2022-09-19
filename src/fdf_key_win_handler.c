/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_win_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:22:54 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/17 17:23:20 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	handle_size(int key, t_fdf *d)
{
	if (key == 3)
	{
		d->win_x = 2560;
		d->win_y = 1400;
		if (d->zoom < 30)
		d->zoom = 30;
	}
	if (key == 4)
	{
		d->win_x = 1280;
		d->win_y = 720;
		if (d->zoom < 20)
		d->zoom = 20;
	}
	if (key == 5)
	{
		d->win_x = 1080;
		d->win_y = 1080;
		if (d->zoom < 20)
		d->zoom = 20;
	}
}

int	full_size(int key, t_fdf *d)
{
	mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	handle_size(key, d);
	d->shift_x = d->win_x / 2;
	d->shift_y = d->win_y / 3;
	d->mlx_ptr = mlx_init();
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->win_x, d->win_y, "FDF");
	draw(d);
	mlx_key_hook(d->win_ptr, key_handler, d);
	mlx_loop(d->mlx_ptr);
	return (0);
}
