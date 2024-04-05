/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:31:32 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/27 19:47:41 by kmatjuhi         ###   ########.fr       */
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
	mlx_delete_image(game.mlx, game.img->wall);
	mlx_delete_image(game.mlx, game.img->collectible);
	mlx_delete_image(game.mlx, game.img->player);
	mlx_delete_image(game.mlx, game.img->exit);
	mlx_delete_image(game.mlx, game.img->free);
	ft_free_arr(game.map);
	return (0);
}
