/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:42:25 by hzibari           #+#    #+#             */
/*   Updated: 2023/11/13 13:59:39 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	l;
	int		len;

	l = c;
	len = ft_strlen(s) + 1;
	while (len > 0)
	{
		if (*s == l)
			return ((char *)s);
		s++;
		len--;
	}
	return (0);
}
