/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:33:29 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/27 17:57:46 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, t_struct *game, int pos_x, int pos_y)
{
	if (map[pos_y][pos_x] == '1' || map[pos_y][pos_x] == 'X')
		return ;
	if (map[pos_y][pos_x] == 'P')
		game->comp.player--;
	if (map[pos_y][pos_x] == 'E')
		game->comp.exit--;
	if (map[pos_y][pos_x] == 'C')
		game->comp.collectible--;
	map[pos_y][pos_x] = 'X';
	flood_fill(map, game, pos_x + 1, pos_y);
	flood_fill(map, game, pos_x - 1, pos_y);
	flood_fill(map, game, pos_x, pos_y + 1);
	flood_fill(map, game, pos_x, pos_y - 1);
	return ;
}
