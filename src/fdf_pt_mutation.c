/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pt_mutation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:08:11 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/14 12:34:06 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	isometric(float *x, float *y, float *z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - *z;
}

static void	ft_zoom(float *x, float *y, fdf_data *data)
{
	*x = *x * data->zoom;
	*y = *y * data->zoom;
}

static void	translation(float *x, float *y, fdf_data *data)
{
	*x += data->shift_x;
	*y += data->shift_y;
}

void	ft_handle_2d(float *x, float *y, fdf_data *data)
{
	ft_zoom(x, y, data);
	translation(x, y, data);
}

void	ft_handle_3d(float *x, float *y, float *z, fdf_data *data)
{
	rotation_xyz(x, y, z, data);
	isometric(x, y, z);
}
