/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:48:16 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/22 11:44:02 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	f_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	line_setter(t_line *l, t_fdf *d, char increment)
{
	if (increment == 'x')
	{
		l->x1 = l->x + 1;
		l->y1 = l->y;
	}
	if (increment == 'y')
	{
		l->x1 = l->x;
		l->y1 = l->y + 1;
	}
	l->z = (d->z_matrix[(int)l->y][(int)l->x]) * d->z_mult;
	l->z1 = (d->z_matrix[(int)l->y1][(int)l->x1]) * d->z_mult;
	l->i_slope = 0;
}

void	line_validation(t_fdf *d, t_line *l)
{
	if (l)
		return ;
	free_all(d);
	malloc_error(d);
}

void	free_all(t_fdf *d)
{
	int	i;

	i = d->height;
	while (i >= 0)
	{
		if (d->z_matrix[i])
			free(d->z_matrix[i]);
		if (d->hex_color[i])
			free(d->hex_color[i]);
		i--;
	}
	free(d->z_matrix);
	free(d->hex_color);
}
