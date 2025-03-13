/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:26:43 by rdos-san          #+#    #+#             */
/*   Updated: 2024/11/04 06:31:52 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_u(unsigned int nb)
{
	int	counter;

	counter = 0;
	if (nb >= 10)
	{
		counter += ft_putnbr_u(nb / 10);
		counter += ft_putnbr_u(nb % 10);
	}
	else
	{
		nb = nb + '0';
		counter += ft_putchar(nb);
	}
	return (counter);
}
