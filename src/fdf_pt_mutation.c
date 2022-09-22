/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pt_mutation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:08:11 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/22 11:22:07 by segarcia         ###   ########.fr       */
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

void	ft_handle_2d(t_line *l, t_fdf *d)
{
	ft_zoom(&l->x, &l->y, d);
	translation(&l->x, &l->y, d);
	ft_zoom(&l->x1, &l->y1, d);
	translation(&l->x1, &l->y1, d);
}

void	ft_handle_3d(t_line *l, t_fdf *d)
{
	rotation_xyz(&l->x, &l->y, &l->z, d);
	isometric(&l->x, &l->y, &l->z);
	rotation_xyz(&l->x1, &l->y1, &l->z1, d);
	isometric(&l->x1, &l->y1, &l->z1);
}
