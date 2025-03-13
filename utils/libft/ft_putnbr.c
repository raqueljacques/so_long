/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:33:13 by rdos-san          #+#    #+#             */
/*   Updated: 2024/11/04 07:39:51 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	int	counter;

	counter = 0;
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return (ft_strlen("-2147483648"));
	}
	if (nb < 0)
	{
		counter += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		counter += ft_putnbr(nb / 10);
		counter += ft_putnbr(nb % 10);
	}
	else
	{
		nb = nb + '0';
		counter += ft_putchar(nb);
	}
	return (counter);
}
