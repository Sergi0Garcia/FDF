/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:50:16 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/12 13:16:58 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fdf_print_menu(fdf_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, "Move img -> |arrow|");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 30, 0xFFFFFF, "2D/3D(iso) -> |i|");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 50, 0xFFFFFF, "Exit -> |esc|");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 70, 0xFFFFFF, "Zoom -> |+| |-|");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 90, 0xFFFFFF, "Z * -> |z| |x|");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 110, 0xFFFFFF, "Rotate x -> |1| |2|");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 130, 0xFFFFFF, "Rotate y -> |3| |4|");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 150, 0xFFFFFF, "Rotate z -> |5| |6|");
}