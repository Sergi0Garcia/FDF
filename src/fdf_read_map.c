/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:41:50 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/15 14:05:05 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY, 0);
	fd_validation(fd);
	height = 0;
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

static int	get_width(char *filename)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(filename, O_RDONLY, 0);
	fd_validation(fd);
	line = get_next_line(fd);
	width = ft_width_counter(line);
	free(line);
	close(fd);
	return (width);
}

void	free_hex(char **hex)
{
	free(hex[0]);
	free(hex[1]);
	free(hex);
}

static void	fill_row_matrix(int *row, int *color, char *line)
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
}

void	read_map(char *filename, t_fdf *d)
{
	int		fd;
	char	*line;
	int		i;

	d->height = get_height(filename);
	d->width = get_width(filename);
	d->z_matrix = (int **)malloc(sizeof(int *) * (d->height + 1));
	if (!d->z_matrix)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	d->hex_color = (int **)malloc(sizeof(int *) * (d->height + 1));
	if (!d->hex_color)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i <= d->height)
	{
		d->z_matrix[i] = (int *)malloc(sizeof(int) * (d->width + 1));
		d->hex_color[i] = (int *)malloc(sizeof(int) * (d->width + 1));
		// TODO FREE WHEN ERROR IN MALLOC
		i++;
	}
	fd = open(filename, O_RDONLY, 0);
	fd_validation(fd);
	i = 0;
	while (i < d->height)
	{
		line = get_next_line(fd);
		fill_row_matrix(d->z_matrix[i], d->hex_color[i], line);
		free(line);
		i++;
	}
	close(fd);
	system("leaks fdf");
}
