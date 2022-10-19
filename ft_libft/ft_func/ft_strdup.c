/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:43:49 by segarcia          #+#    #+#             */
/*   Updated: 2022/08/29 14:16:35 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index_ft_func.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	size;
	size_t	i;

	size = ft_strlen((char *)s1);
	cpy = (char *)malloc(sizeof(char) * (size + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
