/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:42:17 by hzibari           #+#    #+#             */
/*   Updated: 2023/12/22 12:41:17 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_counter(unsigned int len)
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

static char	*ft_uitoa(unsigned int n)
{
	char	*dst;
	int		count;
	int		c;

	count = len_counter(n);
	dst = malloc(sizeof(char) * (count + 1));
	if (dst == 0)
		return (0);
	dst[count] = '\0';
	while (count > 0)
	{
		count--;
		c = n % 10 + 48;
		n = n / 10;
		dst[count] = c;
	}
	return (dst);
}

int	unsigned_printer(unsigned int i)
{
	int		print_lenght;
	char	*nbr;

	nbr = ft_uitoa(i);
	if (nbr == 0)
	{
		free(nbr);
		return (-1);
	}
	print_lenght = string_printer(nbr);
	if (print_lenght < 0)
	{
		free(nbr);
		return (-1);
	}
	free(nbr);
	return (print_lenght);
}
