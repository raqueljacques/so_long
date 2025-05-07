/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:00:39 by rdos-san          #+#    #+#             */
/*   Updated: 2025/04/01 21:15:36 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calculate_length(char *s)
{
	if (!s)
		return (0);
	return (ft_strlen(s));
}

static char	*append_and_free(char *dest, char *src, size_t *index)
{
	char	*temp;

	temp = src;
	while (*src)
		dest[(*index)++] = *src++;
	free(temp);
	return (dest);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;
	size_t	i;

	len1 = calculate_length(s1);
	len2 = calculate_length(s2);
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (s1)
		str = append_and_free(str, s1, &i);
	if (s2)
		while (*s2)
			str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
