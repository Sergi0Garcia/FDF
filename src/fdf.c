/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:19:02 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/14 14:33:46 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	set_default(fdf_data *data)
{
	data->z_mult = 1;
	data->rotation_x = 0.0;
	data->rotation_y = 0.0;
	data->rotation_z = 0.0;
	data->zoom = 10;
	data->win_x = 1280;
	data->win_y = 720;
	data->shift_x = data->win_x / 2;
	data->shift_y = data->win_y / 3;
	data->is_isometric = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_x, data->win_y, "FDF");
}

int	main(int argc, char **argv)
{
	fdf_data	*fdf;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <filename>\n");
		exit(1);
	}
	fdf = (fdf_data *)malloc(sizeof(fdf_data));
	set_default(fdf);
	read_map(argv[1], fdf);
	draw(fdf);
	mlx_key_hook(fdf->win_ptr, key_handler, fdf);
	mlx_loop(fdf->mlx_ptr);
	system("leaks fdf");
}
