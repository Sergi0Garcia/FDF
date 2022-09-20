/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:11:21 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/20 12:57:14 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	handle_max_width_finder(int *max_width, int width, int i)
{
	if (i == 0)
		*max_width = width;
	if (width > *max_width)
		*max_width = width;
}

int	get_height(char *filename)
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

int	get_width(char *filename, int height)
{
	int		fd;
	int		i;
	int		width;
	int		max_width;
	char	*line;

	i = 0;
	width = 2;
	fd = open(filename, O_RDONLY, 0);
	fd_validation(fd);
	line = get_next_line(fd);
	while (line && width > 1 && i < height)
	{
		width = ft_width_counter(line);
		handle_max_width_finder(&max_width, width, i);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	if (width <= 1)
		map_format_error();
	return (max_width);
}
