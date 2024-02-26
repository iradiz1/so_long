/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:20:44 by hzibari           #+#    #+#             */
/*   Updated: 2023/11/13 13:59:22 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				h;
	unsigned char		j;
	char				*g;

	g = b;
	j = c;
	h = 0;
	while (h != len)
	{
		g[h] = j;
		h++;
	}
	return (b);
}
