/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:25:44 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/27 14:31:06 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_texture(t_struct *game)
{
	game->texture = ft_calloc(1, sizeof(t_texture));
	game->texture->wall = mlx_load_png("./images/wall.png");
	game->texture->collectible = mlx_load_png("./images/collect.png");
	game->texture->player = mlx_load_png("./images/player.png");
	game->texture->exit_open = mlx_load_png("./images/open_exit.png");
	game->texture->free = mlx_load_png("./images/free.png");
}

void	texture_to_image(t_struct *game)
{
	game->img = ft_calloc(1, sizeof(t_image));
	game->img->wall = mlx_texture_to_image(game->mlx, game->texture->wall);
	game->img->collectible = mlx_texture_to_image(game->mlx, \
	game->texture->collectible);
	game->img->player = mlx_texture_to_image(game->mlx, game->texture->player);
	game->img->exit_open = mlx_texture_to_image(game->mlx, \
	game->texture->exit_open);
	game->img->free = mlx_texture_to_image(game->mlx, game->texture->free);
	mlx_delete_texture(game->texture->wall);
	mlx_delete_texture(game->texture->collectible);
	mlx_delete_texture(game->texture->player);
	mlx_delete_texture(game->texture->exit_open);
	mlx_delete_texture(game->texture->free);
}

void	image_to_window(t_struct *game, char **map, int i, int j)
{
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->img->wall, \
				j * SIZE, i * SIZE);
			else if (map[i][j] == 'P')
				mlx_image_to_window(game->mlx, game->img->player, \
				j * SIZE, i * SIZE);
			else if (map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->img->collectible, \
				j * SIZE, i * SIZE);
			else if (map[i][j] == '0')
				mlx_image_to_window(game->mlx, game->img->free, \
				j * SIZE, i * SIZE);
			else if (map[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->img->free, \
				j * SIZE, i * SIZE);
			j++;
		}
		j = 0;
		i++;
	}
}
