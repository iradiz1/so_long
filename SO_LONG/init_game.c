/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:36:57 by hzibari           #+#    #+#             */
/*   Updated: 2024/02/26 14:41:21 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_game *g, int x, int y)
{
	if (g->map.full[y][x] == WALL)
	{
		if (mlx_image_to_window(g->mlx, g->img.wall, x * WIDTH, y * HEIGHT) < 0)
			ft_error("ERROR: image to window, wall");
	}
	if (g->map.full[y][x] == FLOOR || g->map.full[y][x] == PLAYER
		|| g->map.full[y][x] == COINS || g->map.full[y][x] == MAP_EXIT)
	{
		if (mlx_image_to_window(g->mlx, g->img.floor,
				x * WIDTH, y * HEIGHT) < 0)
			ft_error("ERROR: image to window, floor");
	}
	if (g->map.full[y][x] == COINS)
	{
		if (mlx_image_to_window(g->mlx, g->img.coins,
				x * WIDTH, y * HEIGHT) < 0)
			ft_error("ERROR: image to window, coins");
	}
	if (g->map.full[y][x] == MAP_EXIT)
	{
		g->exit_x = x;
		g->exit_y = y;
	}
}

static void	ft_image_to_window(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map.rows)
	{
		x = 0;
		while (x < g->map.columns)
		{
			put_image(g, x, y);
			x++;
		}
		y++;
	}
	if (g->map.full[g->map.player.y][g->map.player.x] == PLAYER)
		if (mlx_image_to_window(g->mlx, g->img.player,
				g->map.player.x * WIDTH, g->map.player.y * HEIGHT))
			ft_error("ERROR: image to window, player");
}

static void	ft_load_more_images(t_game *game)
{
	static mlx_texture_t	*player;
	static mlx_texture_t	*exit;

	player = mlx_load_png("./textures/player.png");
	if (!player)
		ft_error("ERROR: player image load failed");
	game->img.player = mlx_texture_to_image(game->mlx, player);
	if (!game->img.player)
		ft_error("ERROR: player image failed ");
	mlx_resize_image(game->img.player, WIDTH, HEIGHT);
	exit = mlx_load_png("./textures/exit.png");
	if (!exit)
		ft_error("ERROR: exit image load failed");
	game->img.exit = mlx_texture_to_image(game->mlx, exit);
	if (!game->img.exit)
		ft_error("ERROR: exit image failed ");
	mlx_resize_image(game->img.exit, WIDTH, HEIGHT);
}

static void	ft_load_images(t_game *game)
{
	static mlx_texture_t	*wall;
	static mlx_texture_t	*floor;
	static mlx_texture_t	*coin;

	wall = mlx_load_png("./textures/wall.png");
	if (!wall)
		ft_error("ERROR: wall image load failed");
	game->img.wall = mlx_texture_to_image(game->mlx, wall);
	if (!game->img.wall)
		ft_error("ERROR: wall image failed ");
	mlx_resize_image(game->img.wall, WIDTH, HEIGHT);
	floor = mlx_load_png("./textures/floor.png");
	if (!floor)
		ft_error("ERROR: floor image load failed");
	game->img.floor = mlx_texture_to_image(game->mlx, floor);
	if (!game->img.floor)
		ft_error("ERROR: floor image failed ");
	mlx_resize_image(game->img.floor, WIDTH, HEIGHT);
	coin = mlx_load_png("./textures/coin.png");
	if (!coin)
		ft_error("ERROR: coin image load failed");
	game->img.coins = mlx_texture_to_image(game->mlx, coin);
	if (!game->img.coins)
		ft_error("ERROR: coin image failed ");
	mlx_resize_image(game->img.coins, WIDTH, HEIGHT);
}

void	ft_init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH * game->map.columns, HEIGHT * game->map.rows,
			"Pixelchu", true);
	if (!game->mlx)
		ft_error("ERROR: mlx failed");
	game->steps = 1;
	ft_load_images(game);
	ft_load_more_images(game);
	ft_image_to_window(game);
	mlx_key_hook(game->mlx, &key_press, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
