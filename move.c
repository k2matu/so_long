/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:28:10 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/27 14:13:47 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_struct *game, int y, int x)
{
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->comp.collectible--;
	}
	if (game->map[y][x] == 'E' && game->comp.collectible == 0)
		mlx_close_window(game->mlx);
	mlx_image_to_window(game->mlx, game->img->free, \
	game->player_pos_x * SIZE, game->player_pos_y * SIZE);
	game->player_pos_y = y;
	game->player_pos_x = x;
	mlx_image_to_window(game->mlx, game->img->player, \
	game->player_pos_x * SIZE, game->player_pos_y * SIZE);
	game->moves++;
	ft_printf("MOVES: %d\n", game->moves);
	if (game->comp.collectible == 0)
		mlx_image_to_window(game->mlx, game->img->exit_open, \
		game->exit_pos_x * SIZE, game->exit_pos_y * SIZE);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_struct	*game;

	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move(game, (game->player_pos_y - 1), game->player_pos_x);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move(game, (game->player_pos_y + 1), game->player_pos_x);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move(game, (game->player_pos_y), game->player_pos_x - 1);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move(game, (game->player_pos_y), game->player_pos_x + 1);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
}
