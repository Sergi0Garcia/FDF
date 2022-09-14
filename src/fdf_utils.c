/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:10:40 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/14 10:36:17 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_hex_to_int(char *hex)
{
	int	i;
	int	val;
	int	dec;
	int	len;

	val = 0;
	i = 0;
	dec = 0;
	len = ft_strlen(hex) - 2;
	while (hex[i])
	{
		if (hex[0] == '0' && hex[1] == 'x' && i == 0)
			i = 2;
		if (hex[i] >= '0' && hex[i] <= '9')
			val = hex[i] - 48;
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			val = hex[i] - 97 + 10;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			val = hex[i] - 65 + 10;
		dec += val * pow(16, len - 1);
		len--;
		i++;
	}
	return (dec);
}
