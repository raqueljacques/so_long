/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:52:17 by rdos-san          #+#    #+#             */
/*   Updated: 2024/11/04 06:56:50 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putpointer(void *pointer)
{
	int					counter;
	unsigned long int	p;

	counter = 0;
	p = (unsigned long int)pointer;
	if (!p)
		return (ft_putstr("(nil)"));
	counter += ft_putstr("0x");
	counter += ft_putnbr_base(p, 'x', 16);
	return (counter);
}
