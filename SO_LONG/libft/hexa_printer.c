/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:57:11 by hzibari           #+#    #+#             */
/*   Updated: 2023/12/22 12:41:37 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_counter(unsigned int len)
{
	int	count;

	count = 0;
	if (len == 0)
		return (1);
	while (len / 16)
	{
		count++;
		len = len / 16;
	}
	count++;
	return (count);
}

static int	hex_calculateor(const char cons, unsigned int i)
{
	if (i >= 16)
	{
		if (hex_calculateor(cons, i / 16) < 0)
			return (-1);
		i = i % 16;
	}
	if (i <= 9)
		if (char_printer(i + 48) < 0)
			return (-1);
	if (i >= 10)
	{
		if (cons == 'x')
			if (char_printer(i - 10 + 'a') < 0)
				return (-1);
		if (cons == 'X')
			if (char_printer(i - 10 + 'A') < 0)
				return (-1);
	}
	return (0);
}

int	hex_printer(const char cons, unsigned int i)
{
	int	print_lenght;

	print_lenght = 0;
	if (i <= 9)
	{
		print_lenght += char_printer(i + 48);
		if (print_lenght < 0)
			return (-1);
		return (print_lenght);
	}
	else
		if (hex_calculateor(cons, i) < 0)
			return (-1);
	return (len_counter(i));
}
