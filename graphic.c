/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:25:44 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/27 20:14:35 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_texture(t_struct *game)
{
	game->texture = ft_calloc(1, sizeof(t_texture));
	if (!game->texture)
		ft_error(game, "Calloc failed", game->map);
	game->texture->wall = mlx_load_png("./images/wall.png");
	game->texture->collectible = mlx_load_png("./images/collect.png");
	game->texture->player = mlx_load_png("./images/player.png");
	game->texture->exit = mlx_load_png("./images/open_exit.png");
	game->texture->free = mlx_load_png("./images/free.png");
	if (!game->texture->wall || !game->texture->collectible || \
	!game->texture->player || !game->texture->exit || !game->texture->free)
		ft_error(NULL, "Mlx texture failed", game->map);
}

static void	texture_to_image(t_struct *game)
{
	game->img = ft_calloc(1, sizeof(t_image));
	if (!game->img)
		ft_error(game, "Calloc failed", game->map);
	game->img->wall = mlx_texture_to_image(game->mlx, game->texture->wall);
	mlx_delete_texture(game->texture->wall);
	game->img->collectible = mlx_texture_to_image(game->mlx, \
	game->texture->collectible);
	mlx_delete_texture(game->texture->collectible);
	game->img->player = mlx_texture_to_image(game->mlx, game->texture->player);
	mlx_delete_texture(game->texture->player);
	game->img->exit = mlx_texture_to_image(game->mlx, game->texture->exit);
	mlx_delete_texture(game->texture->exit);
	game->img->free = mlx_texture_to_image(game->mlx, game->texture->free);
	mlx_delete_texture(game->texture->free);
	if (!game->img->wall || !game->img->collectible || \
	!game->img->player || !game->img->exit || !game->img->free)
		ft_error(game, "Mlx texture to image failed", game->map);
}

void	draw_img_to_win(t_struct *game, mlx_image_t *image, int j, int i)
{
	if (mlx_image_to_window(game->mlx, image, j * SIZE, i * SIZE) < 0)
		ft_error(game, "Draw image to window failed", game->map);
}

void	image_to_window(t_struct *game, char **map, int i, int j)
{
	get_texture(game);
	texture_to_image(game);
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '1')
				draw_img_to_win(game, game->img->wall, j, i);
			else if (map[i][j] == 'P')
				draw_img_to_win(game, game->img->player, j, i);
			else if (map[i][j] == 'C')
				draw_img_to_win(game, game->img->collectible, j, i);
			else if (map[i][j] == '0')
				draw_img_to_win(game, game->img->free, j, i);
			else if (map[i][j] == 'E')
				draw_img_to_win(game, game->img->free, j, i);
			j++;
		}
		j = 0;
		i++;
	}
}
