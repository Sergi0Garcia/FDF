/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:50:16 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/14 14:22:40 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fdf_print_menu(fdf_data *d)
{
	int	color;

	color = 0xFFFFFF;
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 10, color, "Move -> arrow");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 30, color, "2D/3D -> i");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 50, color, "Exit -> esc");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 70, color, "Zoom -> +, -");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 90, color, "Z * -> z, x");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 110, color, "Rotate x -> 1, 2");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 130, color, "Rotate y -> 3, 4");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 150, color, "Rotate z -> 5, 6");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 180, color, "--- screen ---");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 200, color, "Full screen -> f");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 220, color, "1080x1080 -> g");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 240, color, "1280x720 -> h");
}
