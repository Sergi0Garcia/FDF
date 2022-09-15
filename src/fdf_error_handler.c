/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:31:42 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/15 13:53:47 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fd_validation(int	fd)
{
	if (fd == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

void	argc_validation(int	argc)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <filename>\n");
		exit(EXIT_FAILURE);
	}
}
