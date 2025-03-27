/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:59:02 by rdos-san          #+#    #+#             */
/*   Updated: 2025/03/27 01:06:28 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_line(char *backup)
{
	char	*line;
	size_t	size;

	if (!*backup)
		return (NULL);
	size = 0;
	while (backup[size] && backup[size] != '\n')
		size++;
	line = malloc(sizeof(char) * (size + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, backup, size + 1);
	if (backup[size] == '\n')
		line[size++] = '\n';
	line[size] = '\0';
	return (line);
}

static char	*handle_read_error(char *backup, char *buffer)
{
	free(backup);
	free(buffer);
	return (NULL);
}

static char	*read_fd(int fd, char *backup)
{
	char	*buffer;
	ssize_t	read_bytes;

	if (!backup)
	{
		backup = malloc(sizeof(char) * 1);
		if (!backup)
			return (NULL);
		*backup = '\0';
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(backup, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (handle_read_error(backup, buffer));
		buffer[read_bytes] = '\0';
		backup = ft_strjoin_free(backup, buffer);
	}
	free(buffer);
	return (backup);
}

static char	*remove_read_line(char *backup)
{
	size_t	i;
	size_t	j;
	char	*new_backup;

	i = 0;
	j = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	i++;
	new_backup = malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!new_backup)
		return (NULL);
	while (backup[i])
		new_backup[j++] = backup[i++];
	new_backup[j] = '\0';
	free(backup);
	return (new_backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_fd(fd, backup);
	if (!backup)
		return (NULL);
	line = get_line(backup);
	backup = remove_read_line(backup);
	free(backup);
	return (line);
}
