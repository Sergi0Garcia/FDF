/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:19:02 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/14 10:55:29 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	set_default(fdf_data *data)
{
	data->z_mult = 1;
	data->shift_x = 700;
	data->shift_y = 300;
	data->rotation_x = 0.0;
	data->rotation_y = 0.0;
	data->rotation_z = 0.0;
	data->zoom = 10;
	data->win_x = 1500;
	data->win_y = 1000;
	data->is_isometric = 0;
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
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_x, fdf->win_y, "FDF");
	draw(fdf);
	mlx_key_hook(fdf->win_ptr, key_handler, fdf);
	mlx_loop(fdf->mlx_ptr);
}
