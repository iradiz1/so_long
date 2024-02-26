/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:49:43 by hzibari           #+#    #+#             */
/*   Updated: 2024/02/21 14:00:39 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_map_content(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("01ECP", game->map.full[y][x]))
				ft_error("ERROR: Invalid map content");
			if (game->map.full[y][x] == COINS)
				game->map.coins++;
			if (game->map.full[y][x] == MAP_EXIT)
				game->map.exit++;
			if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			x++;
		}
		y++;
	}
}

static void	ft_check_map_border(t_game *game)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (game->map.full[i])
	{
		while (game->map.full[i][c])
		{
			if (game->map.full[0][c] != WALL)
				ft_error("ERROR; Wall missing from first row");
			if (game->map.full[game->map.rows - 1][c] != WALL)
				ft_error("ERROR: Wall missing from last row");
			c++;
		}
		if (game->map.full[i][0] != WALL)
			ft_error("ERROR: Wall missing from first column");
		if (game->map.full[i][game->map.columns - 1] != WALL)
			ft_error("ERROR: Wall missing from last column");
		i++;
	}
}

static void	ft_check_map_size(t_game *game)
{
	int	i;
	int	len;
	int	temp_len;

	i = 0;
	if (game->map.full[0] == NULL)
		ft_error("ERROR: Map file is empty");
	len = ft_strlen(game->map.full[i]);
	game->map.columns = len;
	while (game->map.full[i])
	{
		temp_len = ft_strlen(game->map.full[i]);
		if (game->map.rows < 3)
			ft_error("ERROR: Map is less then 3 rows");
		if (len != temp_len)
			ft_error("ERROR: Map is not rectangular, all rows have to be \
the same lenght");
		i++;
	}
}

void	ft_check_map(t_game *game)
{
	ft_check_map_size(game);
	ft_check_map_border(game);
	ft_check_map_content(game);
	if (game->map.players != 1)
		ft_error("ERROR: Invalid amount of players");
	if (game->map.coins == 0)
		ft_error("ERROR: There are no collectables");
	if (game->map.exit != 1)
		ft_error("ERROR: Invalide amount of exits");
}
