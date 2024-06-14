/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 00:28:54 by aalissa           #+#    #+#             */
/*   Updated: 2024/03/14 14:30:11 by aalissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	word_count(char *str, char sep)
{
	size_t	count;
	bool	in_word;

	count = 0;
	while (*str)
	{
		in_word = false;
		while (*str == sep && *str)
			++str;
		while (*str != sep && *str)
		{
			if (!in_word)
			{
				++count;
				in_word = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char sep)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == sep)
		++cursor;
	while ((str[cursor + len] != sep) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != sep) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char sep)
{
	int		words;
	char	**artificial;
	int		i;

	i = 0;
	words = word_count(str, sep);
	if (!words)
		exit(1);
	artificial = malloc(sizeof(char *) * (size_t)(words + 2));
	if (NULL == artificial)
		return (NULL);
	while (words-- >= 0)
	{
		if (0 == i)
		{
			artificial[i] = malloc(sizeof(char));
			if (NULL == artificial[i])
				return (NULL);
			artificial[i++][0] = '\0';
			continue ;
		}
		artificial[i++] = get_next_word(str, sep);
	}
	artificial[i] = NULL;
	return (artificial);
}
