/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:21:51 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/12 13:32:50 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	rotation_x(float *y, int *z, fdf_data *data)
{
	float	ac_y;
	float	ac_z;

	ac_y = *y;
	ac_z = *z;
	*y = (cos(data->rotation_x) * ac_y) - (sin(data->rotation_x) * ac_z);
	*z = (sin(data->rotation_x) * ac_y) + (cos(data->rotation_x) * ac_z);
}

static void	rotation_y(float *x, int *z, fdf_data *data)
{
	float	ac_x;
	float	ac_z;

	ac_x = *x;
	ac_z = *z;
	*x = (cos(data->rotation_y) * ac_x) + (sin(data->rotation_y) * ac_z);
	*z = -(sin(data->rotation_y) * ac_x) + (cos(data->rotation_y) * ac_z);
}

static void	rotation_z(float *x, float *y, fdf_data *data)
{
	float	ac_x;
	float	ac_y;

	ac_x = *x;
	ac_y = *y;
	*x = (cos(data->rotation_z) * ac_x) - (sin(data->rotation_z) * ac_y);
	*y = (sin(data->rotation_z) * ac_x) + (cos(data->rotation_z) * ac_y);
}

void	rotation(float *x, float *y, int *z, fdf_data *data)
{
	rotation_x(y, z, data);
	rotation_y(x, z, data);
	rotation_z(x, y, data);
}
