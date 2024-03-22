/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:31:32 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/22 13:01:44 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	static t_struct	game;
	char			**map;

	game = (t_struct){{0}, 0};
	if (!validate_map(argc, argv, &game))
		return (1);
	map = parse_map(argv[1]);
	game.mlx = mlx_init(game.columns * SIZE, game.rows * SIZE, "so_long", 1);
	if (!game.mlx)
		return (-1);
	get_texture(&game);
	texture_to_image(&game);
	image_to_window(&game, map);
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (0);
}