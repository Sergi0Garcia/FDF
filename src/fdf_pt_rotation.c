/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pt_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:21:51 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/17 15:23:00 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	rotation_x(float *y, float *z, t_fdf *d)
{
	float	ac_y;
	float	ac_z;

	ac_y = *y;
	ac_z = *z;
	*y = (cos(d->rotation_x) * ac_y) - (sin(d->rotation_x) * ac_z);
	*z = (sin(d->rotation_x) * ac_y) + (cos(d->rotation_x) * ac_z);
}

static void	rotation_y(float *x, float *z, t_fdf *d)
{
	float	ac_x;
	float	ac_z;

	ac_x = *x;
	ac_z = *z;
	*x = (cos(d->rotation_y) * ac_x) + (sin(d->rotation_y) * ac_z);
	*z = -(sin(d->rotation_y) * ac_x) + (cos(d->rotation_y) * ac_z);
}

static void	rotation_z(float *x, float *y, t_fdf *d)
{
	float	ac_x;
	float	ac_y;

	ac_x = *x;
	ac_y = *y;
	*x = (cos(d->rotation_z) * ac_x) - (sin(d->rotation_z) * ac_y);
	*y = (sin(d->rotation_z) * ac_x) + (cos(d->rotation_z) * ac_y);
}

void	rotation_xyz(float *x, float *y, float *z, t_fdf *d)
{
	rotation_x(y, z, d);
	rotation_y(x, z, d);
	rotation_z(x, y, d);
}
