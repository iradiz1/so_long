/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:35:26 by hzibari           #+#    #+#             */
/*   Updated: 2024/02/26 13:32:21 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit (1);
}

void	ft_free(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free (temp);
}

void	collect_coin(t_game *game)
{
	int	x;
	int	y;
	int	i;

	i = -1;
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.full[y][x] == COINS)
				i++;
			if (x == game->map.player.x && y == game->map.player.y)
			{
				if (game->img.coins->instances[i].enabled != 0)
				{
					game->img.coins->instances[i].enabled = 0;
					game->map.coins--;
				}
			}
			x++;
		}
		y++;
	}
}
