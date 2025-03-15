/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:32:38 by rdos-san          #+#    #+#             */
/*   Updated: 2024/11/04 06:53:40 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned long number, const char ref, int base)
{
	int		counter;
	char	*chars_base;

	counter = 0;
	if (ref == 'x')
		chars_base = "0123456789abcdef";
	else
		chars_base = "0123456789ABCDEF";
	if (number >= (unsigned long)base)
	{
		counter += ft_putnbr_base((number / base), ref, base);
		counter += ft_putnbr_base((number % base), ref, base);
	}
	else
	{
		counter += ft_putchar(chars_base[number]);
	}
	return (counter);
}
