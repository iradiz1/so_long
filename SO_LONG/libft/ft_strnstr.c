/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:58:52 by hzibari           #+#    #+#             */
/*   Updated: 2023/11/13 14:00:02 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	int				t;

	i = 0;
	t = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (haystack == 0 && len == 0)
		return (0);
	while (haystack[i] != '\0' && i <= len)
	{
		while (haystack[i + t] == needle[t] && haystack[i + t] != '\0'
			&& i + t < len && needle[t] != '\0')
			t++;
		if (needle[t] == '\0')
			return ((char *)haystack + i);
		i++;
		t = 0;
	}
	return (0);
}
