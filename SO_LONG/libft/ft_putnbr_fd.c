/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:39:26 by hzibari           #+#    #+#             */
/*   Updated: 2023/11/13 13:59:30 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	in;

	in = nb;
	if (in < 0)
	{
		ft_putchar_fd('-', fd);
		in = -in;
	}
	if (in < 10)
	{
		ft_putchar_fd(in + '0', fd);
	}
	else
	{
		ft_putnbr_fd(in / 10, fd);
		ft_putchar_fd(in % 10 + '0', fd);
	}
}
