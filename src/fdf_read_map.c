/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:41:50 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/19 13:21:46 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(filename, O_RDONLY, 0);
	fd_validation(fd);
	line = get_next_line(fd);
	while (line && ft_strlen(line))
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static int	get_width(char *filename, int height)
{
	int		fd;
	int		i;
	int		width;
	int		max_width;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY, 0);
	fd_validation(fd);
	line = get_next_line(fd);
	while (line && ft_strlen(line) && i < height)
	{
		width = ft_width_counter(line);
		if (i == 0)
			max_width = width;
		if (width > max_width)
			max_width = width;
		if (width <= 1)
		{
			free(line);
			map_format_error();
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	system("leaks fdf");
	return (max_width);
}

void	free_hex(char **hex)
{
	free(hex[0]);
	free(hex[1]);
	free(hex);
}

static void	fill_row_matrix(int *row, int *color, char *line, int width)
{
	char	**num;
	char	**hex;
	int		i;

	num = ft_split(line, ' ');
	i = 0;
	while (num[i])
	{
		if (is_valid_hex_format(num[i]))
		{
			hex = ft_split(num[i], ',');
			row[i] = ft_atoi(hex[0]);
			color[i] = ft_hex_to_int(hex[1]);
			free(num[i]);
			free_hex(hex);
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
	if (i - width != 0)
	{
		while(i < width)
		{
			row[i] = 0;
			color[i] = 0;
			i++;
		}
	}
	system("leaks fdf");
}

void	read_map(char *filename, t_fdf *d)
{
	int		fd;
	char	*line;
	int		i;

	d->height = get_height(filename);
	d->width = get_width(filename, d->height);
	allocate_matrixes(d);
	i = 0;
	while (i <= d->height)
	{
		allocate_imatrix(d, i);
		i++;
	}
	fd = open(filename, O_RDONLY, 0);
	fd_validation(fd);
	i = 0;
	while (i < d->height)
	{
		line = get_next_line(fd);
		fill_row_matrix(d->z_matrix[i], d->hex_color[i], line, d->width);
		free(line);
		i++;
	}
	close(fd);
}
