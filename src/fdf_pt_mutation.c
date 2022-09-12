/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pt_mutation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:08:11 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/12 14:33:57 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric(float *x, float *y, float *z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - *z;
}

void	ft_zoom(float *x, float *y, fdf_data *data)
{
	*x = *x * data->zoom;
	*y = *y * data->zoom;
}

void	translation(float *x, float *y, fdf_data *data)
{
	*x += data->shift_x;
	*y += data->shift_y;
}