/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:42:49 by rdos-san          #+#    #+#             */
/*   Updated: 2024/10/24 19:38:39 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *string)
{
	int	i;
	int	n;
	int	sign;

	sign = 1;
	i = 0;
	n = 0;
	while (string[i] == ' ' || string[i] == '\n' || string[i] == '\f'
		|| string[i] == '\t' || string[i] == '\v' || string[i] == '\r')
		i++;
	if (string[i] == '-' || string[i] == '+')
	{
		if (string[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (string[i] != '\0' && ft_isdigit(string[i]))
	{
		n = n * 10;
		n = n + string[i] - '0';
		i++;
	}
	return (n * sign);
}
