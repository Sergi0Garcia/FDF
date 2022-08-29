/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:19:02 by segarcia          #+#    #+#             */
/*   Updated: 2022/08/29 12:35:07 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// int	deal_key(int key, void *data)
// {
// 	ft_printf("%d", key);
// 	return (0);
// }

int		get_height(char *filename)
{
	int fd;
	// char *line;
	int	 height;

	fd = open(filename, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd))
	{
		height++;
		// free(line);
	}
	close(fd);
	ft_printf("%i\n", height);
	return (height);
}

void	read_file(char *filename, fdf *data)
{
	data->height = get_height(filename);
}

int main(int argc, char **argv)
{
	fdf	*data;

	if (argc != 2)
		return (-1);
	data = (fdf*)malloc(sizeof(fdf));
	read_file(argv[1], data);
}