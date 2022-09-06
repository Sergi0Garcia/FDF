/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:19:44 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/06 12:55:07 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx_macos/mlx.h"
# include "./ft_libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

typedef struct
{
	int	width;
	int height;
	int **z_matrix;
	int zoom;
	int	color;
	int shift_x;
	int shift_y;
	float rotation_x;
	float rotation_y;
	float rotation_z;

	void *mlx_ptr;
	void *win_ptr;
}	fdf;

void	draw(fdf *data);

#endif