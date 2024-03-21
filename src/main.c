/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:31:32 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/21 15:17:37 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_texture(t_struct *game)
{
	game->texture = ft_calloc(1, sizeof(t_texture));
	game->texture->wall = mlx_load_png("./images/wall.png");
	game->texture->collectible = mlx_load_png("./images/collect.png");
	game->texture->player = mlx_load_png("./images/player.png");
	game->texture->exit_closed = mlx_load_png("./images/closed_exit.png");
	game->texture->exit_open = mlx_load_png("./images/open_exit.png");
	game->texture->free = mlx_load_png("./images/free.png");
}

void	texture_to_image(t_struct *game)
{
	game->img = ft_calloc(1, sizeof(t_image));
	game->img->wall = mlx_texture_to_image(game->mlx, game->texture->wall);
	game->img->collectible = mlx_texture_to_image(game->mlx, game->texture->collectible);
	game->img->player = mlx_texture_to_image(game->mlx, game->texture->player);
	game->img->exit_closed = mlx_texture_to_image(game->mlx, game->texture->exit_closed);
	game->img->exit_open = mlx_texture_to_image(game->mlx, game->texture->exit_open);
	game->img->free = mlx_texture_to_image(game->mlx, game->texture->free);
	mlx_delete_texture(game->texture->wall);
	mlx_delete_texture(game->texture->collectible);
	mlx_delete_texture(game->texture->player);
	mlx_delete_texture(game->texture->exit_closed);
	mlx_delete_texture(game->texture->exit_open);
	mlx_delete_texture(game->texture->free);
}

void	image_to_window(t_struct *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == WALL)
				mlx_image_to_window(game->mlx, game->img->wall, i * SIZE, j * SIZE);
			j++;
		}
		j = 0;
		i++;
	}
}

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
	// Display the image

	// mlx_image_t *img = mlx_new_image(mlx, 50, 50);
	// ft_memset(img->pixels, 100, img->width * img->height * sizeof(int32_t));
	// mlx_image_to_window(mlx, img, 50, 50);
	mlx_loop(game.mlx);
	return (0);
}

// int32_t	main(void)
// {
// 	// Start mlx
// 	mlx_t* mlx = mlx_init(140, 140, "Test", true);
// 	if (!mlx)
//         return (-1);

// 	// Try to load the file
// 	mlx_texture_t* texture = mlx_load_png("./images/Wall.png");
// 	if (!texture)
// 		return (-1);
	
// 	// Convert texture to a displayable image
// 	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
// 	if (!img)
//         return (-1);

// 	// Display the image
// 	if (mlx_image_to_window(mlx, img, 70, 70) < 0)
//         return (-1);

// 	mlx_loop(mlx);

// 	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
// 	mlx_delete_image(mlx, img);
// 	mlx_delete_texture(texture);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }