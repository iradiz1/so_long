/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:25:53 by hzibari           #+#    #+#             */
/*   Updated: 2023/12/22 12:42:33 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_counter(uintptr_t len)
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

static int	hex_calculateor(uintptr_t i)
{
	if (i >= 16)
	{
		if (hex_calculateor(i / 16) < 0)
			return (-1);
		i = i % 16;
	}
	if (i <= 9)
	{
		if (char_printer(i + 48) < 0)
			return (-1);
	}
	else
		if (char_printer(i - 10 + 'a') < 0)
			return (-1);
	return (0);
}

int	adress_printer(uintptr_t i)
{
	int	print_lenght;

	print_lenght = string_printer("0x");
	if (print_lenght < 0)
		return (-1);
	if (i == 0)
	{
		print_lenght += char_printer('0');
		if (print_lenght < 0)
			return (-1);
		return (print_lenght);
	}
	else
		hex_calculateor(i);
	return (len_counter(i) + print_lenght);
}
