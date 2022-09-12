/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:19:02 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/12 13:33:04 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	deal_key(int key, fdf_data *data)
{
	ft_printf("%d\n", key);
	int val;
	if (key == 34)
	{
		val = data->is_isometric;
		if (val == 1)
			data->is_isometric = 0;
		if (val == 0)
			data->is_isometric = 1;
	}
	if (key == 18)
		data->rotation_x -= 0.1;
	if (key == 19)
		data->rotation_x += 0.1;
	if (key == 20)
		data->rotation_y -= 0.1;
	if (key == 21)
		data->rotation_y += 0.1;
	if (key == 22)
		data->rotation_z -= 0.1;
	if (key == 23)
		data->rotation_z += 0.1;
	if (key == 126)
		data->shift_y -= 50;
	if (key == 125)
		data->shift_y += 50;
	if (key == 6)
		data->z_mult += 0.2;
	if (key == 7)
		data->z_mult -= 0.2;
	if (key == 123)
		data->shift_x -= 50;
	if (key == 124)
		data->shift_x += 50;
	if (key == 24)
		data->zoom += 10;
	if (key == 27)
	{
		if (data->zoom <= 1)
			data->zoom /= 2;
		else
		 data->zoom -= 2;
	}
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data);
		exit(0);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	get_height(char *filename)
{
	int	fd;
	int	height;

	fd = open(filename, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd);
	return (height);
}

int	get_width(char *filename)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	width = ft_width_counter(line);
	free(line);
	close(fd);
	return (width);
}

int	is_valid_hex_format(char *str)
{
	int i;
	int	len;
	int cc;

	i = 0;
	cc = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == ',')
			cc++;
		i++;
	}
	if (cc == 1)
		return (1);
	return (0);
}

void	fill_row_matrix(int *row, int *color, char *line)
{
	char	**num;
	char	**hex;
	int		i;
	int 	flag;

	num = ft_split(line, ' ');
	i = 0;
	flag = 0;
	while(num[i])
	{
		if (is_valid_hex_format(num[i]))
		{
			flag = 1;
			hex = ft_split(num[i], ',');
			row[i] = ft_atoi(hex[0]);
			color[i] = ft_hex_to_int(hex[1]);
			free(num[i]);
			free(hex[0]);
			free(hex[1]);
		}
		else
		{
			row[i] = ft_atoi(num[i]);
			color[i] = 0;
			free(num[i]);
		}
		i++;
	}
	free(num);
	if (flag)
		free(hex);
}

void	read_file(char *filename, fdf_data *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(filename);
	data->width = get_width(filename);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	data->hex_color = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i<=data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		data->hex_color[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		i++;
	}
	fd = open(filename, O_RDONLY, 0);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_row_matrix(data->z_matrix[i], data->hex_color[i], line);
		free(line);
		i++;
	}
	close(fd);
}

void set_default(fdf_data *data)
{
	data->z_mult = 1;
	data->shift_x = 500;
	data->shift_y = 300;
	data->rotation_x = 0.0;
	data->rotation_y = 0.0;
	data->rotation_z = 0.0;
	data->zoom = 10;
	data->win_x = 1000;
	data->win_y = 1000;
	data->is_isometric = 0;
}

int	main(int argc, char **argv)
{
	fdf_data	*data;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <filename>\n");
		exit(1);
	}
	data = (fdf_data *)malloc(sizeof(fdf_data));
	set_default(data);
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_x, data->win_y, "FDF");
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
