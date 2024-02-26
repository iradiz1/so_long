/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:55:49 by hzibari           #+#    #+#             */
/*   Updated: 2023/12/22 12:43:02 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_printer(int c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

int	string_printer(char *p)
{
	int	i;

	i = 0;
	if (p == '\0')
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	while (p[i] != '\0')
	{
		if (write(1, &p[i], 1) < 0)
			return (-1);
		i++;
	}
	return (i);
}

int	check_cons(va_list ap, const char cons)
{
	int		print_lenght;

	print_lenght = 0;
	if (cons == 'c')
		print_lenght += char_printer(va_arg(ap, int));
	else if (cons == 's')
		print_lenght += string_printer(va_arg(ap, char *));
	else if (cons == 'p')
		print_lenght += adress_printer(va_arg(ap, unsigned long));
	else if (cons == 'd' || cons == 'i')
		print_lenght += numbr_printer(va_arg(ap, int));
	else if (cons == 'u')
		print_lenght += unsigned_printer(va_arg(ap, unsigned int));
	else if (cons == 'x' || cons == 'X')
		print_lenght += hex_printer(cons, va_arg(ap, unsigned int));
	else if (cons == '%')
		print_lenght += char_printer('%');
	return (print_lenght);
}

static int	sender(va_list ap, const char *str, int c, int print_lenght)
{
	int	result;

	result = 0;
	while (str[c] != '\0')
	{
		if (str[c] == '%')
		{
			result = check_cons(ap, str[c + 1]);
			if (result == -1)
				return (-1);
			print_lenght += result;
			c++;
		}
		else
		{
			result = char_printer(str[c]);
			if (result == -1)
				return (-1);
			print_lenght += result;
		}
		c++;
	}
	return (print_lenght);
}

int	ft_printf(const char *str, ...)
{
	int			print_lenght;
	int			c;
	va_list		ap;

	print_lenght = 0;
	c = 0;
	va_start(ap, str);
	print_lenght = sender(ap, str, c, print_lenght);
	va_end(ap);
	if (print_lenght < 0)
		return (-1);
	return (print_lenght);
}
