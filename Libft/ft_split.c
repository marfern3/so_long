/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marfern3 <marfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:59:16 by marfern3          #+#    #+#             */
/*   Updated: 2024/10/09 11:01:28 by marfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_delimiter(char s, char c)
{
	return (s == c);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (!is_delimiter(*s, c) && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (is_delimiter(*s, c))
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*malloc_word(char const *s, char c)
{
	char	*word;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[len] && !is_delimiter(s[len], c))
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**fill_split(char **split, char const *s, char c, size_t words)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] && j < words)
	{
		while (s[i] && is_delimiter(s[i], c))
			i++;
		if (s[i])
		{
			split[j] = malloc_word(&s[i], c);
			if (!split[j])
				return (NULL);
			j++;
			while (s[i] && !is_delimiter(s[i], c))
				i++;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	words;
	size_t	j;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	split = (char **)malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (!fill_split(split, s, c, words))
	{
		j = 0;
		while (split[j])
			free(split[j++]);
		free(split);
		return (NULL);
	}
	return (split);
}
