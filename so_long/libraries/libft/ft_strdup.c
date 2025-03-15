/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 23:25:55 by rdos-san          #+#    #+#             */
/*   Updated: 2024/10/25 11:07:40 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*new_string;
	int		i;

	i = 0;
	while (src[i])
		i++;
	new_string = (char *)malloc(sizeof(char) * (i + 1));
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new_string[i] = src[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
