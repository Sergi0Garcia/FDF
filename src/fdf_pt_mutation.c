/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pt_mutation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:08:11 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/17 15:23:14 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	isometric(float *x, float *y, float *z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - *z;
}

static void	ft_zoom(float *x, float *y, t_fdf *d)
{
	*x = *x * d->zoom;
	*y = *y * d->zoom;
}

static void	translation(float *x, float *y, t_fdf *d)
{
	*x += d->shift_x;
	*y += d->shift_y;
}

void	ft_handle_2d(float *x, float *y, t_fdf *d)
{
	ft_zoom(x, y, d);
	translation(x, y, d);
}

void	ft_handle_3d(float *x, float *y, float *z, t_fdf *d)
{
	rotation_xyz(x, y, z, d);
	isometric(x, y, z);
}
