/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:53:57 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/14 13:56:54 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	is_valid_key(int key)
{
	return (key == 6 || key == 7 || key == 18 || key == 19 || key == 20
		|| key == 21 || key == 22 || key == 23 || key == 24 || key == 27
		|| key == 34 || key == 53 || key == 123 || key == 124 || key == 125
		|| key == 126 || key == 3 || key == 4 || key == 5);
}

static void	handle_translation(int key, fdf_data *data)
{
	if (key == 123)
		data->shift_x -= 50;
	if (key == 124)
		data->shift_x += 50;
	if (key == 125)
		data->shift_y += 50;
	if (key == 126)
		data->shift_y -= 50;
}

static void	handle_rotation(int key, fdf_data *data)
{
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
}

static void	handle_mutation(int key, fdf_data *data)
{
	int	val;
	if (key == 6)
		data->z_mult += 0.2;
	if (key == 7)
		data->z_mult -= 0.2;
	if (key == 24)
		data->zoom += 5;
	if (key == 27)
	{
		if (data->zoom -2 <= 1)
			data->zoom /= 2;
		else
			data->zoom -= 2;
	}
	if (key == 34)
	{
		val = data->is_isometric;
		if (val == 1)
			data->is_isometric = 0;
		if (val == 0)
			data->is_isometric = 1;
	}
}

int	key_handler(int key, fdf_data *data)
{
	ft_printf("Key: %i\n", key);
	if (is_valid_key(key))
	{
		if (key == 3 || key == 4 || key == 5)
			return (full_size(key, data));
		if (key > 17 && key < 24)
			handle_rotation(key, data);
		else if (key > 122 && key < 127)
			handle_translation(key, data);
		else if (key != 53)
			handle_mutation(key, data);
		else if (key == 53)
		{
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			free(data);
			exit(0);
		}
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}
