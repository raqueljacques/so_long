/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:22:45 by rdos-san          #+#    #+#             */
/*   Updated: 2025/04/01 21:23:02 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*handle_read_error(char *backup, char *buffer)
{
	free(backup);
	free(buffer);
	return (NULL);
}

size_t	find_newline_position(char *backup)
{
	size_t	i;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	return (i);
}
