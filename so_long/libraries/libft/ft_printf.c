/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:38:45 by rdos-san          #+#    #+#             */
/*   Updated: 2024/11/04 17:54:30 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_next(va_list args, const char *s)
{
	int	c;

	c = 0;
	if (*s == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*s == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*s == 'p')
		return (ft_putpointer(va_arg(args, void *)));
	else if (*s == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (*s == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*s == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (*s == 'x' || *s == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), *s, 16));
	else if (*s == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	int		c;
	va_list	args;

	va_start(args, s);
	c = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		if (*s == '%')
		{
			c += check_next(args, (s + 1));
			s += 2;
			continue ;
		}
		c += ft_putchar(*s++);
	}
	va_end(args);
	return (c);
}
