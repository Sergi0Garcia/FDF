/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:31:42 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/22 11:33:26 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fd_validation(int fd, t_fdf *d)
{
	if (fd == -1)
	{
		if (d)
			free_all(d);
		perror("Error");
		system("leaks fdf");
		exit(EXIT_FAILURE);
	}
}

void	argc_validation(int argc)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <filename>\n");
		system("leaks fdf");
		exit(EXIT_FAILURE);
	}
}

void	map_format_error(void)
{
	ft_printf("Found wrong line length. Exiting.\n");
	system("leaks fdf");
	exit(EXIT_FAILURE);
}

void	malloc_error(t_fdf *d)
{
	if (d->mlx_ptr && d->win_ptr)
		mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	ft_printf("Memory allocation error\n");
	system("leaks fdf");
	exit(EXIT_FAILURE);
}
