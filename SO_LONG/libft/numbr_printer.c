/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbr_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:08:41 by hzibari           #+#    #+#             */
/*   Updated: 2023/12/22 12:41:24 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numbr_printer(int i)
{
	int		print_lenght;
	char	*nbr;

	print_lenght = 0;
	if (i == 0)
		return (char_printer('0'));
	nbr = ft_itoa(i);
	if (nbr == 0)
	{
		free(nbr);
		return (-1);
	}
	print_lenght = string_printer(nbr);
	free(nbr);
	return (print_lenght);
}
