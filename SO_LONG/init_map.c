/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:09:14 by hzibari           #+#    #+#             */
/*   Updated: 2024/02/26 12:41:51 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_for_empty_lines(char *temp_map)
{
	int	i;

	i = 0;
	if (temp_map[0] == '\n')
		ft_error("ERROR: First line in map is empty");
	else if (temp_map[ft_strlen(temp_map) - 1] == '\n')
		ft_error("ERROR: Last line in map is empty");
	while (temp_map[i + 1])
	{
		if (temp_map[i] == '\n' && temp_map[i + 1] == '\n')
			ft_error("ERROR: Empty line somewhere in the middle of the map");
		i++;
	}
}

static void	get_ready_to_flood(char **map_temp, t_game *game)
{
	int	x;
	int	y;
	int	coins;
	int	exit;

	if (!map_temp)
		ft_error("ERROR: split failed");
	x = game->map.player.x;
	y = game->map.player.y;
	coins = game->map.coins;
	exit = game->map.exit;
	flood_fill_map(map_temp, x, y, game);
	if (game->map.coins != 0)
	{
		ft_free (map_temp);
		ft_error("ERROR: Invalid path to coins");
	}
	if (game->map.exit != 0)
	{
		ft_free (map_temp);
		ft_error("ERROR: Invalid path to exit");
	}
	game->map.coins = coins;
	game->map.exit = exit;
	ft_free (map_temp);
}

static void	check_split_flood(t_game *game, char *map_temp)
{
	ft_check_for_empty_lines(map_temp);
	game->map.full = ft_split(map_temp, '\n');
	if (!game->map.full)
		ft_error("ERROR: split malloc failed");
	ft_check_map(game);
	get_ready_to_flood(ft_split(map_temp, '\n'), game);
	free(map_temp);
}

void	ft_init_map(t_game *game, char *argv, int fd)
{
	char	*lines;
	char	*map_temp;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error("ERROR: Unable to open mapfile");
	map_temp = strdup("");
	if (!map_temp)
		ft_error("ERROR: strdup malloc failed");
	game->map.rows = 0;
	while (1)
	{
		lines = get_next_line(fd);
		if (lines == NULL)
			break ;
		map_temp = join_line(map_temp, lines);
		if (!map_temp)
			ft_error("ERROR: join_linee failed");
		free(lines);
		game->map.rows++;
	}
	close(fd);
	check_split_flood(game, map_temp);
}
