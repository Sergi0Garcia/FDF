/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pt_mutation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:08:11 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/20 14:42:17 by segarcia         ###   ########.fr       */
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

void	ft_handle_2d(t_line *p, t_fdf *d)
{
	ft_zoom(&p->x, &p->y, d);
	translation(&p->x, &p->y, d);
	ft_zoom(&p->x1, &p->y1, d);
	translation(&p->x1, &p->y1, d);
}

void	ft_handle_3d(t_line *p, t_fdf *d)
{
	rotation_xyz(&p->x, &p->y, &p->z, d);
	isometric(&p->x, &p->y, &p->z);
	rotation_xyz(&p->x1, &p->y1, &p->z1, d);
	isometric(&p->x1, &p->y1, &p->z1);
}
