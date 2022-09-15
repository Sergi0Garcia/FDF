/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:19:44 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/15 13:53:10 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx_macos/mlx.h"
# include "./ft_libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		**hex_color;
	int		color;
	float	z_mult;
	int		shift_x;
	int		shift_y;
	float	rotation_x;
	float	rotation_y;
	float	rotation_z;
	int		zoom;
	int		win_x;
	int		win_y;
	int		is_isometric;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

typedef struct s_plane
{
	float	x_step;
	float	y_step;
	float	x;
	float	y;
	float	x1;
	float	y1;
	float	z;
	float	z1;
}	t_plane;

int		key_handler(int key, t_fdf *d);
void	draw(t_fdf *d);
int		ft_hex_to_int(char *hex);
void	fdf_print_menu(t_fdf *d);
void	rotation_xyz(float *x, float *y, float *z, t_fdf *d);
void	read_map(char *filename, t_fdf *d);
void	ft_handle_2d(float *x, float *y, t_fdf *d);
void	ft_handle_3d(float *x, float *y, float *z, t_fdf *d);
int		full_size(int key, t_fdf *d);
int		is_valid_hex_format(char *str);
float	f_max(float a, float b);
void	fd_validation(int fd);
void	argc_validation(int	argc);
#endif