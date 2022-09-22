/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:20:54 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/22 11:42:10 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_with_i(int i, t_fdf *d, int err)
{
	int	idx;

	idx = i - 1;
	if (err == 1)
		free(d->z_matrix[i]);
	while (idx >= 0)
	{
		free(d->z_matrix[idx]);
		free(d->hex_color[idx]);
		idx--;
	}
	free(d->z_matrix);
	free(d->hex_color);
	malloc_error(d);
}

void	allocate_matrixes(t_fdf *d)
{
	d->z_matrix = (int **)malloc(sizeof(int *) * (d->height + 1));
	if (!d->z_matrix)
		malloc_error(d);
	d->hex_color = (int **)malloc(sizeof(int *) * (d->height + 1));
	if (!d->hex_color)
	{
		free(d->z_matrix);
		malloc_error(d);
	}
}

void	allocate_imatrix(t_fdf *d, int i)
{
	d->z_matrix[i] = (int *)malloc(sizeof(int) * (d->width + 1));
	if (!d->z_matrix[i])
		free_with_i(i, d, 0);
	d->hex_color[i] = (int *)malloc(sizeof(int) * (d->width + 1));
	if (!d->hex_color[i])
		free_with_i(i, d, 1);
}
