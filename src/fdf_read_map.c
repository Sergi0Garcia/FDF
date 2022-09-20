/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:41:50 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/20 13:22:15 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_hex_num(char *num, char **hex)
{
	free(num);
	if (hex)
	{
		free(hex[0]);
		free(hex[1]);
		free(hex);
	}
}

void	handle_extra_map(int i, int *row, int *color, int width)
{
	int	ix;

	ix = i;
	if (ix - width != 0)
	{
		while (ix < width)
		{
			row[ix] = 0;
			color[ix] = 0;
			ix++;
		}
	}
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
			free_hex_num(num[i], hex);
		}
		else
		{
			row[i] = ft_atoi(num[i]);
			color[i] = 0;
			free_hex_num(num[i], 0);
		}
		i++;
	}
	free(num);
	handle_extra_map(i, row, color, width);
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
