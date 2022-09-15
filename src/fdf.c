/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:19:02 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/15 11:39:52 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	set_default(t_fdf *d)
{
	d->z_mult = 1;
	d->rotation_x = 0.0;
	d->rotation_y = 0.0;
	d->rotation_z = 0.0;
	d->zoom = 10;
	d->win_x = 2560;
	d->win_y = 1400;
	d->shift_x = d->win_x / 2;
	d->shift_y = d->win_y / 3;
	d->is_isometric = 0;
	d->mlx_ptr = mlx_init();
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->win_x, d->win_y, "FDF");
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <filename>\n");
		exit(1);
	}
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	set_default(fdf);
	read_map(argv[1], fdf);
	draw(fdf);
	mlx_key_hook(fdf->win_ptr, key_handler, fdf);
	mlx_loop(fdf->mlx_ptr);
	system("leaks fdf");
}
