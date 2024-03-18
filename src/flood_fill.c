/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:33:29 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/18 12:09:57 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int pos_x, int pos_y)
{
	if (map[pos_x][pos_y] == WALL || map[pos_x][pos_y] == 'X')
		return ;

	map[pos_x][pos_y] = 'X';

	flood_fill(map, pos_x + 1, pos_y);
	flood_fill(map, pos_x - 1, pos_y);
	flood_fill(map, pos_x, pos_y + 1);
	flood_fill(map, pos_x, pos_y - 1);

	return ;
}
