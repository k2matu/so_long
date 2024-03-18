/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:25:12 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/18 10:25:50 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_invalid_component_and_shape(char **map, int column)
{
	int	row;

	row = 0;
	printf("column %d\n", column);
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
	printf("row %d\n", row);
	if (row < 3)
		ft_error("Map too small", map);
	return (row);
}

void	check_components(char **map, t_struct game)
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
				game.components.collectible++;
			else if (map[i][j] == EXIT)
				game.components.exit++;
			else if (map[i][j] == PLAYER)
				game.components.player++;
			j++;
		}
		j = 0;
	}
	if (game.components.collectible < 1 || game.components.player != 1 \
	|| game.components.exit != 1)
		ft_error("Map must contain 1 exit, 1 startposition & collectible", map);
}

void	check_surrounding_walls(char **map, int row, int column)
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

// void check_valid_path(char **map)
// {
	
// }

char	**parse_map(char *str)
{
	char	**two_d_map;
	char	*map;

	map = read_file(str);
	two_d_map = ft_split(map, '\n');
	free(map);
	return (two_d_map);
}

int	validate_map(int argc, char **argv, t_struct game)
{
	char	**map;
	int		rows;
	int		column;

	if (argc != 2 || ft_strrcmp(argv[1], ".ber") != 0 || ft_strlen(argv[1]) < 5)
		ft_error("Mapfile must end with .ber extension.", NULL);
	map = parse_map(argv[1]);
	column = ft_strlen(map[0]);
	rows = check_invalid_component_and_shape(map, column);
	check_components(map, game);
	check_surrounding_walls(map, rows, column);
	return (0);
}