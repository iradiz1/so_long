/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:40:30 by hzibari           #+#    #+#             */
/*   Updated: 2024/02/14 11:06:58 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_right(char **map_temp, int x, int y, t_game *game)
{
	if (map_temp[y][x + 1] != WALL)
	{
		if (map_temp[y][x + 1] == COINS)
			game->map.coins--;
		if (map_temp[y][x + 1] == MAP_EXIT)
			game->map.exit--;
		map_temp[y][x + 1] = WALL;
		flood_fill_map(map_temp, x + 1, y, game);
	}
}

static void	fill_left(char **map_temp, int x, int y, t_game *game)
{
	if (map_temp[y][x - 1] != WALL)
	{
		if (map_temp[y][x - 1] == COINS)
			game->map.coins--;
		if (map_temp[y][x - 1] == MAP_EXIT)
			game->map.exit--;
		map_temp[y][x - 1] = WALL;
		flood_fill_map(map_temp, x - 1, y, game);
	}
}

static void	fill_up(char **map_temp, int x, int y, t_game *game)
{
	if (map_temp[y + 1][x] != WALL)
	{
		if (map_temp[y + 1][x] == COINS)
			game->map.coins--;
		if (map_temp[y + 1][x] == MAP_EXIT)
			game->map.exit--;
		map_temp[y + 1][x] = WALL;
		flood_fill_map(map_temp, x, y + 1, game);
	}
}

static void	fill_down(char **map_temp, int x, int y, t_game *game)
{
	if (map_temp[y - 1][x] != WALL)
	{
		if (map_temp[y - 1][x] == COINS)
			game->map.coins--;
		if (map_temp[y - 1][x] == MAP_EXIT)
			game->map.exit--;
		map_temp[y - 1][x] = WALL;
		flood_fill_map(map_temp, x, y - 1, game);
	}
}

void	flood_fill_map(char **map_temp, int x, int y, t_game *game)
{
	fill_right(map_temp, x, y, game);
	fill_left(map_temp, x, y, game);
	fill_up(map_temp, x, y, game);
	fill_down(map_temp, x, y, game);
}