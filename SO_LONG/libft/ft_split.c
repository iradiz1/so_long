/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:03:21 by hzibari           #+#    #+#             */
/*   Updated: 2023/11/13 13:59:36 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	size_t	words;

	words = 0;
	if (s == 0)
		return (0);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			words++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (words);
}

static char	**free_all(char **s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char		**dst;
	size_t		i;
	size_t		start;
	size_t		end;

	i = 0;
	start = 0;
	dst = (char **) ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (dst == 0 || s == 0)
		return (0);
	while (s[start] != '\0')
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		if (s[start] == '\0')
			return (dst);
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		dst[i] = ft_substr(s, start, end - start);
		if (dst[i++] == '\0')
			return (free_all(dst));
		start = end;
	}
	return (dst);
}
