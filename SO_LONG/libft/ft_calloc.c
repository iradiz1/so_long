/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:55:22 by hzibari           #+#    #+#             */
/*   Updated: 2023/11/16 14:51:17 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	max;

	max = 0 - 1;
	if (count != 0 && size != 0)
		if (max / count < size)
			return (0);
	if ((count * size) > 2147483423)
		return (0);
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero (ptr, count * size);
	return (ptr);
}
