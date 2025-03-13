/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:03:00 by rdos-san          #+#    #+#             */
/*   Updated: 2024/10/25 11:04:41 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	is_word;
	int	count;

	i = 0;
	is_word = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && !is_word)
		{
			is_word = 1;
			count++;
		}
		else if (s[i] == c)
		{
			is_word = 0;
		}
		i++;
	}
	return (count);
}

static void	free_all(char **split, int index)
{
	while (index >= 0)
	{
		free(split[index]);
		index--;
	}
	free(split);
}

static char	*alloc_word(const char *str, int start, int end)
{
	char	*word;
	int		len;
	int		i;

	len = end - start;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i++] = str[start++];
	}
	word[i] = '\0';
	return (word);
}

static int	put_words(const char *str, char c, char **split)
{
	int	i;
	int	start;
	int	word_index;

	i = 0;
	word_index = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			start = i;
			while (str[i] != '\0' && str[i] != c)
				i++;
			split[word_index] = alloc_word(str, start, i);
			if (!split[word_index])
				return (0);
			word_index++;
		}
		else
			i++;
	}
	split[word_index] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	if (!put_words(s, c, split))
	{
		free_all(split, words);
		return (NULL);
	}
	return (split);
}
