/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:50:12 by hzibari           #+#    #+#             */
/*   Updated: 2024/02/08 12:13:47 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	a;
	unsigned char	*p;
	unsigned char	*d;

	p = (unsigned char *)s1;
	d = (unsigned char *)s2;
	a = 0;
	if (n == 0)
		return (0);
	while (p[a] == d[a] && p[a] != '\0' && a < n - 1)
		a++;
	return (p[a] - d[a]);
}
