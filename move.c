/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:28:10 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/27 17:17:08 by kmatjuhi         ###   ########.fr       */
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
	draw_img_to_win(game, game->img->free, game->player_x, game->player_y);
	game->player_y = y;
	game->player_x = x;
	draw_img_to_win(game, game->img->player, game->player_x, game->player_y);
	game->moves++;
	if (ft_printf("MOVES: %d\n", game->moves) == -1)
		ft_error(game, "ft_printf function failed", game->map);
	if (game->comp.collectible == 0)
		draw_img_to_win(game, game->img->exit, game->exit_x, game->exit_y);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_struct	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS) || \
	(keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT))
		move(game, (game->player_y - 1), game->player_x);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS) || \
	(keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT))
		move(game, (game->player_y + 1), game->player_x);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS) || \
	(keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT))
		move(game, (game->player_y), game->player_x - 1);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS) || \
	(keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT))
		move(game, (game->player_y), game->player_x + 1);
}
