/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:29:23 by hzibari           #+#    #+#             */
/*   Updated: 2024/01/25 12:17:22 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit (0);
}

int	ft_atoi(const char *str)
{
	int long		i;
	int long		m;
	int long long	p;

	i = 0;
	m = 1;
	p = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		p = p * 10 + (str[i] - 48);
		i++;
	}
	if (p * m > 2147483647 || p * m < -2147483648)
		ft_error("Error");
	return (p * m);
}
