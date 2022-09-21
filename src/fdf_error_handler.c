/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:31:42 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/21 15:00:12 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fd_validation(int fd)
{
	if (fd == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

void	argc_validation(int argc)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <filename>\n");
		exit(EXIT_FAILURE);
	}
}

void	map_format_error(void)
{
	ft_printf("Found wrong line length. Exiting.\n");
	exit(EXIT_FAILURE);
}

void	malloc_error(t_fdf *d)
{
	if (d->mlx_ptr && d->win_ptr)
		mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	ft_printf("Memory allocation error\n");
	exit(EXIT_FAILURE);
}

void	mlx_error(void)
{
	ft_printf("mlx init error\n");
	exit(EXIT_FAILURE);
}
