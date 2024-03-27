/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:31:32 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/27 18:09:27 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	static t_struct	game;

	game = (t_struct){{0}, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	validate_map(argc, argv, &game);
	game.map = parse_map(argv[1]);
	game.mlx = mlx_init(game.columns * SIZE, game.rows * SIZE, "so_long", 1);
	if (!game.mlx)
		ft_error(NULL, "Mlx init failed", NULL);
	image_to_window(&game, game.map, 0, 0);
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	ft_free_arr(game.map);
	return (0);
}
