/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:40:57 by hzibari           #+#    #+#             */
/*   Updated: 2023/11/13 13:59:50 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	i;

	dlen = 0;
	i = 0;
	while (dlen < size && dst[dlen] != '\0')
		dlen++;
	while (src[i] != '\0' && (dlen + i + 1) < size)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	if (dlen != size)
		dst[dlen + i] = '\0';
	return (dlen + ft_strlen(src));
}
