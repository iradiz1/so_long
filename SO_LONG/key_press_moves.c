/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:55:17 by hzibari           #+#    #+#             */
/*   Updated: 2024/02/26 14:40:44 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_game *game)
{
	if (game->map.full[game->map.player.y - 1][game->map.player.x] == WALL)
		return ;
	game->map.player.y--;
	game->img.player->instances->y -= HEIGHT;
	ft_printf("%d\n", game->steps++);
	if (game->map.full[game->map.player.y][game->map.player.x] == COINS)
	{
		collect_coin(game);
	}
	if (game->map.coins == 0)
	{
		if (mlx_image_to_window(game->mlx, game->img.exit,
				game->exit_x * WIDTH, game->exit_y * HEIGHT) < 0)
			ft_error("ERROR: image to window, exit");
	}
	if (game->map.full[game->map.player.y][game->map.player.x] == MAP_EXIT
			&& game->map.coins == 0)
	{
		ft_printf("You win!\n");
		mlx_close_window(game->mlx);
	}
}

static void	move_down(t_game *game)
{
	if (game->map.full[game->map.player.y + 1][game->map.player.x] == WALL)
		return ;
	game->map.player.y++;
	game->img.player->instances->y += HEIGHT;
	ft_printf("%d\n", game->steps++);
	if (game->map.full[game->map.player.y][game->map.player.x] == COINS)
	{
		collect_coin(game);
	}
	if (game->map.coins == 0)
	{
		if (mlx_image_to_window(game->mlx, game->img.exit,
				game->exit_x * WIDTH, game->exit_y * HEIGHT) < 0)
			ft_error("ERROR: image to window, exit");
	}
	if (game->map.full[game->map.player.y][game->map.player.x] == MAP_EXIT
			&& game->map.coins == 0)
	{
		ft_printf("You win!\n");
		mlx_close_window(game->mlx);
	}
}

static void	move_left(t_game *game)
{
	if (game->map.full[game->map.player.y][game->map.player.x - 1] == WALL)
		return ;
	game->map.player.x--;
	game->img.player->instances->x -= WIDTH;
	ft_printf("%d\n", game->steps++);
	if (game->map.full[game->map.player.y][game->map.player.x] == COINS)
	{
		collect_coin(game);
	}
	if (game->map.coins == 0)
	{
		if (mlx_image_to_window(game->mlx, game->img.exit,
				game->exit_x * WIDTH, game->exit_y * HEIGHT) < 0)
			ft_error("ERROR: image to window, exit");
	}
	if (game->map.full[game->map.player.y][game->map.player.x] == MAP_EXIT
		&& game->map.coins == 0)
	{
		ft_printf("You win!\n");
		mlx_close_window(game->mlx);
	}
}

static void	move_right(t_game *game)
{
	if (game->map.full[game->map.player.y][game->map.player.x + 1] == WALL)
		return ;
	game->map.player.x++;
	game->img.player->instances->x += WIDTH;
	ft_printf("%d\n", game->steps++);
	if (game->map.full[game->map.player.y][game->map.player.x] == COINS)
	{
		collect_coin(game);
	}
	if (game->map.coins == 0)
	{
		if (mlx_image_to_window(game->mlx, game->img.exit,
				game->exit_x * WIDTH, game->exit_y * HEIGHT) < 0)
			ft_error("ERROR: image to window, exit");
	}
	if (game->map.full[game->map.player.y][game->map.player.x] == MAP_EXIT
			&& game->map.coins == 0)
	{
		ft_printf("You win!\n");
		mlx_close_window(game->mlx);
	}
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_up(game);
	if (keydata.key == MLX_KEY_S
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_down(game);
	if (keydata.key == MLX_KEY_A
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_left(game);
	if (keydata.key == MLX_KEY_D
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_right(game);
}
