/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_counter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:47:17 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/15 13:37:53 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index_ft_extra.h"

int	ft_width_counter(char *line)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
			i++;
		if (line[i])
			w++;
		while (line[i] != ' ' && line[i])
			i++;
	}
	return (w);
}
