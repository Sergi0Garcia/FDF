/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:19:02 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/12 14:16:22 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void set_default(fdf_data *data)
{
	data->z_mult = 1;
	data->shift_x = 500;
	data->shift_y = 300;
	data->rotation_x = 0.0;
	data->rotation_y = 0.0;
	data->rotation_z = 0.0;
	data->zoom = 10;
	data->win_x = 1000;
	data->win_y = 1000;
	data->is_isometric = 0;
}

int	main(int argc, char **argv)
{
	fdf_data	*data;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <filename>\n");
		exit(1);
	}
	data = (fdf_data *)malloc(sizeof(fdf_data));
	set_default(data);
	read_map(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_x, data->win_y, "FDF");
	draw(data);
	mlx_key_hook(data->win_ptr, key_handler, data);
	mlx_loop(data->mlx_ptr);
}
