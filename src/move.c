/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:28:10 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/22 12:40:35 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_up(t_struct *game)
{
	if (game->map[game->player_pos_x - 1][game->player_pos_y] != WALL)
	{
		mlx_image_to_window(game->mlx, game->img->free, game->player_pos_x * SIZE, game->player_pos_y * SIZE);
		game->player_pos_x = game->player_pos_x - 1;
		mlx_image_to_window(game->mlx, game->img->player, game->player_pos_x * SIZE, game->player_pos_y * SIZE);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_struct	*game;

	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		key_up(game);
}