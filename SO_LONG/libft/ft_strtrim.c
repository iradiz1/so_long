/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:42:45 by hzibari           #+#    #+#             */
/*   Updated: 2023/11/13 14:00:08 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	int		c;
	int		d;
	char	*res;

	c = 0;
	i = 0;
	if (s1 == 0 || set == 0)
		return (0);
	d = ft_strlen(s1);
	len = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) != 0 && i <= len)
		i++;
	if (i >= len)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[len]) != 0)
	{
		c++;
		len--;
	}
	res = ft_substr(s1, i, d - i - c);
	return (res);
}
