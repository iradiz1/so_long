/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:24:12 by hzibari           #+#    #+#             */
/*   Updated: 2024/02/26 12:37:11 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static void	ft_check_input(int argc, char **argv)
{
	int	map_filename_len;

	if (argc > 2)
		ft_error("ERROR: Too many arguments");
	if (argc < 2)
		ft_error("ERROR: The map file is missing");
	map_filename_len = ft_strlen(argv[1]);
	if (map_filename_len == 4)
		ft_error("ERROR: No name on the file");
	if (!ft_strnstr(&argv[1][map_filename_len - 4], ".ber", 4))
		ft_error("ERROR: Wrong map file extention (should be .ber)");
}

int	main(int argc, char **argv)
{
	static t_game	*game;
	int				fd;

	fd = 0;
	game = malloc (sizeof(t_game));
	ft_check_input(argc, argv);
	ft_init_map(game, argv[1], fd);
	ft_init_game(game);
	ft_free(game->map.full);
}
