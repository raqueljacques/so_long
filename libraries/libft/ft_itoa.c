/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 23:35:47 by rdos-san          #+#    #+#             */
/*   Updated: 2024/10/25 10:50:50 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_size(long int n)
{
	int	i;	

	i = 0;
	if (n <= 0)
	{
		i++;
		if (n == 0)
			return (1);
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*s;
	int			size;
	long int	number;

	number = (long int) n;
	size = n_size(number);
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	s[size] = '\0';
	if (number == 0)
		*s = '0';
	if (number < 0)
	{
		s[0] = '-';
		number *= -1;
	}
	while (number > 0)
	{
		s[size - 1] = number % 10 + 48;
		number = number / 10;
		size--;
	}
	return (s);
}
