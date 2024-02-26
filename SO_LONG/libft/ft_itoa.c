/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:21:22 by hzibari           #+#    #+#             */
/*   Updated: 2023/11/15 10:24:47 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_counter(int len)
{
	int	count;

	count = 0;
	if (len == 0)
		return (1);
	while (len / 10)
	{
		count++;
		len = len / 10;
	}
	count++;
	return (count);
}

static char	*copy_over(char *dst, int count, int minus, long int n)
{
	int	c;

	dst[count + minus] = '\0';
	while (count + minus > 0)
	{
		count--;
		c = n % 10 + 48;
		n = n / 10;
		dst[count + minus] = c;
	}
	if (minus > 0)
		dst[count + minus] = '-';
	return (0);
}

char	*ft_itoa(int n)
{
	char		*dst;
	int			count;
	int			minus;
	long int	l;

	l = n;
	minus = 0;
	count = len_counter(n);
	if (l < 0)
	{
		minus = 1;
		l *= -1;
	}
	dst = malloc(sizeof(char) * (count + minus + 1));
	if (dst == 0)
		return (0);
	copy_over(dst, count, minus, l);
	return (dst);
}
