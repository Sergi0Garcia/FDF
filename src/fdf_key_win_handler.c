/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_win_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:22:54 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/14 14:04:35 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fdf.h"

static void	handle_size(int key, fdf_data *data)
{
	if (key == 3)
	{
		data->win_x = 2560;
		data->win_y = 1400;
		if (data->zoom < 30)
		data->zoom = 30;
		data->shift_x = data->win_x / 2;
		data->shift_y = data->win_y / 3;
	}
	if (key == 4)
	{
		data->win_x = 1280;
		data->win_y = 720;
		if (data->zoom < 20)
		data->zoom = 20;
		data->shift_x = data->win_x / 2;
		data->shift_y = data->win_y / 3;
	}
	if (key == 5)
	{
		data->win_x = 1080;
		data->win_y = 1080;
		if (data->zoom < 20)
		data->zoom = 20;
		data->shift_x = data->win_x / 2;
		data->shift_y = data->win_y / 3;
	}
}

int	full_size(int key, fdf_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	handle_size(key, data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_x, data->win_y, "FDF");
	draw(data);
	mlx_key_hook(data->win_ptr, key_handler, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
