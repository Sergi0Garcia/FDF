/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:19:44 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/14 10:56:03 by segarcia         ###   ########.fr       */
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
	int **hex_color;
	int	color;
	float z_mult;
	int shift_x;
	int shift_y;
	float rotation_x;
	float rotation_y;
	float rotation_z;
	int zoom;
	int	win_x;
	int win_y;
	int is_isometric;
	void *mlx_ptr;
	void *win_ptr;
}	fdf_data;

typedef struct
{
	float	x_step;
	float	y_step;
	float	x;
	float 	y;
	float	x1;
	float	y1;
	float	z;
	float	z1;
}	point;

int		key_handler(int key, fdf_data *data);
void	draw(fdf_data *data);
int		ft_hex_to_int(char *hex);
void	fdf_print_menu(fdf_data *data);
void	rotation_xyz(float *x, float *y, float *z, fdf_data *data);
void	read_map(char *filename, fdf_data *data);
void	ft_handle_2d(float *x, float *y, fdf_data *data);
void	ft_handle_3d(float *x, float *y, float *z, fdf_data *data);
#endif