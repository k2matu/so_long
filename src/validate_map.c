/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:25:12 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/19 11:44:39 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_invalid_comp_and_shape(char **map, int column)
{
	int	row;

	row = 0;
	if (column < 4)
		ft_error("Map too small", map);
	while (map[row] != NULL)
	{
		if (column != ft_strlen(map[row]))
			ft_error("Map must be rectangular", map);
		if (ft_match(map[row], "01CEP") != 1)
			ft_error("Invalid map components", map);
		row++;
	}
	if (row < 3)
		ft_error("Map too small", map);
	return (row);
}

static void	check_components(char **map, t_struct *game)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[++i] != NULL)
	{
		while (map[i][j])
		{
			if (map[i][j] == COLLECTIBLE)
				game->comp.collectible++;
			else if (map[i][j] == EXIT)
				game->comp.exit++;
			else if (map[i][j] == PLAYER)
				game->comp.player++;
			j++;
		}
		j = 0;
	}
	if (game->comp.collectible < 1 || game->comp.player != 1 \
	|| game->comp.exit != 1)
		ft_error("Map must contain 1 exit, 1 startposition & collectible", map);
}

static void	check_surrounding_walls(char **map, int row, int column)
{
	int	i;

	i = -1;
	while (++i < column - 1)
	{
		if (map[0][i] != WALL || map[row - 1][i] != WALL)
			ft_error("Map must be surrounded by walls.", map);
	}
	i = -1;
	while (++i < row - 1)
	{
		if (map[i][0] != WALL || map[i][column - 1] != WALL)
			ft_error("Map must be surrounded by walls.", map);
	}
}

static void	find_player_pos(char **map, t_struct *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == PLAYER)
			{
				game->player_pos_x = j;
				game->player_pos_y = i;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	validate_map(int argc, char **argv, t_struct *game)
{
	char	**map;
	int		rows;
	int		column;
	int		collectible;

	if (argc != 2 || ft_strrcmp(argv[1], ".ber") != 0 || ft_strlen(argv[1]) < 5)
		ft_error("Mapfile must end with .ber extension.", NULL);
	map = parse_map(argv[1]);
	column = ft_strlen(map[0]);
	rows = check_invalid_comp_and_shape(map, column);
	check_components(map, game);
	check_surrounding_walls(map, rows, column);
	find_player_pos(map, game);
	collectible = game->comp.collectible;
	flood_fill(map, game, game->player_pos_x, game->player_pos_y);
	if (game->comp.exit != 0 || game->comp.player != 0 \
	|| game->comp.collectible != 0)
		return (0);
	game->comp.collectible = collectible;
	printf("ALL OK");
	return (1);
}
