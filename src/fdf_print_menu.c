/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:50:16 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/22 11:24:13 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fdf_print_menu(t_fdf *d)
{
	int	color;

	color = 0xFFFFFF;
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 10, color, "Move -> arrow");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 30, color, "2D/3D -> i");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 50, color, "Exit -> esc");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 70, color, "Zoom -> +, -");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 90, color, "Z * -> z, x");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 110, color, "Blur -> b");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 130, color, "Rotate x -> 1, 2");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 150, color, "Rotate y -> 3, 4");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 170, color, "Rotate z -> 5, 6");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 190, color, "--- screen ---");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 210, color, "Full screen -> f");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 230, color, "1080x1080 -> g");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 250, color, "1280x720 -> h");
}
