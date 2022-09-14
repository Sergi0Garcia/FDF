/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:53:57 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/14 10:56:06 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_handler(int key, fdf_data *data)
{
	int val;
	if (key == 34)
	{
		val = data->is_isometric;
		if (val == 1)
			data->is_isometric = 0;
		if (val == 0)
			data->is_isometric = 1;
	}
	if (key == 18)
		data->rotation_x -= 0.1;
	if (key == 19)
		data->rotation_x += 0.1;
	if (key == 20)
		data->rotation_y -= 0.1;
	if (key == 21)
		data->rotation_y += 0.1;
	if (key == 22)
		data->rotation_z -= 0.1;
	if (key == 23)
		data->rotation_z += 0.1;
	if (key == 126)
		data->shift_y -= 50;
	if (key == 125)
		data->shift_y += 50;
	if (key == 6)
		data->z_mult += 0.2;
	if (key == 7)
		data->z_mult -= 0.2;
	if (key == 123)
		data->shift_x -= 50;
	if (key == 124)
		data->shift_x += 50;
	if (key == 24)
		data->zoom += 10;
	if (key == 27)
	{
		if (data->zoom <= 1)
			data->zoom /= 2;
		else
		 data->zoom -= 2;
	}
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data);
		exit(0);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}
