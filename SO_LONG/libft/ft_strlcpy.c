/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:47:49 by hzibari           #+#    #+#             */
/*   Updated: 2023/11/15 09:45:10 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	g;

	g = 0;
	if (dstsize == 0)
	{
		while (src[g] != '\0')
			g++;
		return (g);
	}
	while (g < dstsize - 1 && src[g] != '\0')
	{
		dst[g] = src[g];
		g++;
	}
	if (g < dstsize)
	{
		dst[g] = '\0';
	}
	while (src[g] != '\0')
		g++;
	return (g);
}
