/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:48:16 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/20 13:28:58 by segarcia         ###   ########.fr       */
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

void	line_setter(t_line *p, t_fdf *d, char increment)
{
	if (increment == 'x')
	{
		p->x1 = p->x + 1;
		p->y1 = p->y;
	}
	if (increment == 'y')
	{
		p->x1 = p->x;
		p->y1 = p->y + 1;
	}
	p->z = (d->z_matrix[(int)p->y][(int)p->x]) * d->z_mult;
	p->z1 = (d->z_matrix[(int)p->y1][(int)p->x1]) * d->z_mult;
	p->i_slope = 0;
}

void	line_validation(t_fdf *d, t_line *p)
{
	int	i;

	if (p)
		return ;
	i = d->height;
	while (i >= 0)
	{
		free(d->z_matrix[i]);
		free(d->hex_color[i]);
		i--;
	}
	free(d->z_matrix);
	free(d->hex_color);
	malloc_error(d);
}
