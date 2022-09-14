/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:41:50 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/14 12:20:28 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	get_height(char *filename)
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

static int	get_width(char *filename)
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

static int	is_valid_hex_format(char *str)
{
	int	i;
	int	len;
	int	cc;

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

static void	fill_row_matrix(int *row, int *color, char *line)
{
	char	**num;
	char	**hex;
	int		i;
	int		flag;

	num = ft_split(line, ' ');
	i = 0;
	flag = 0;
	while (num[i])
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

void	read_map(char *filename, fdf_data *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(filename);
	data->width = get_width(filename);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	data->hex_color = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
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
