/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:24:05 by hzibari           #+#    #+#             */
/*   Updated: 2024/02/26 14:37:36 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./lib/MLX42/include/MLX42/MLX42.h"

# define WIDTH 70
# define HEIGHT 70

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'

typedef struct s_position
{
	int	x;
	int	y;
}	t_positon;

typedef struct s_image
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*coins;
	mlx_image_t	*exit;
	mlx_image_t	*player;
}	t_image;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			coins;
	int			exit;
	int			players;
	t_positon	player;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	int			movements;
	int			player_sprite;
	int			exit_x;
	int			exit_y;
	int			steps;
	t_map		map;
	t_image		img;
}	t_game;

void	ft_error(char *msg);
void	ft_init_map(t_game *game, char *argv, int fd);
void	ft_check_for_empty_lines(char *temp_map);
void	flood_fill_map(char **map_temp, int x, int y, t_game *game);
void	ft_check_map(t_game *game);
void	ft_free(char **temp);
void	ft_init_game(t_game *game);
void	key_press(mlx_key_data_t keydata, void *param);
void	collect_coin(t_game *game);

#endif