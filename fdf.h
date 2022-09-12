/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:19:44 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/12 14:33:56 by segarcia         ###   ########.fr       */
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

int		key_handler(int key, fdf_data *data);
void	draw(fdf_data *data);
int		ft_hex_to_int(char *hex);
void	fdf_print_menu(fdf_data *data);
void	rotation_xyz(float *x, float *y, float *z, fdf_data *data);
void	read_map(char *filename, fdf_data *data);
void	translation(float *x, float *y, fdf_data *data);
void	isometric(float *x, float *y, float *z);
void	ft_zoom(float *x, float *y, fdf_data *data);

#endif