/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_win_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:22:54 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/14 14:25:34 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	handle_size(int key, fdf_data *data)
{
	if (key == 3)
	{
		data->win_x = 2560;
		data->win_y = 1400;
		if (data->zoom < 30)
		data->zoom = 30;
	}
	if (key == 4)
	{
		data->win_x = 1280;
		data->win_y = 720;
		if (data->zoom < 20)
		data->zoom = 20;
	}
	if (key == 5)
	{
		data->win_x = 1080;
		data->win_y = 1080;
		if (data->zoom < 20)
		data->zoom = 20;
	}
}

int	full_size(int key, fdf_data *d)
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
