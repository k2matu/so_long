/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:31:32 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/13 14:15:50 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_characters(char **map)
{
	int	player;
	int	collectible;
	int	exit;
	int	i;
	int	j;

	player = 0;
	collectible = 0;
	exit = 0;
	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		if (ft_match(map[i], "01CEP") != 1)
		{
			printf("INVALID MAP");
			return (0);
		}
		while (map[i][j])
		{
			if (map[i][j] == COLLECTIBLE)
				collectible++;
			else if (map[i][j] == EXIT)
				exit++;
			else if (map[i][j] == PLAYER)
				player++;
		}
		
	}
}

void check_surrounding_walls(char **map)
{
	
}

void check_valid_path(char **map)
{
	
}

char	**parse_map(char *str)
{
	char	*map;
	char	**two_d_map;

	map = read_file(str);
	two_d_map = ft_split(map, '\n');
	free(map);
	return (two_d_map);
}

int	validate_map(int argc, char **argv)
{
	char	**map;

	if (argc != 2 || ft_strrcmp(argv[1], ".ber") != 0 || ft_strlen(argv[1]) < 5)
		return (-1);
	map = parse_map(argv[1]);
	check_map(map);
	return (0);
}

int	main(int argc, char **argv)
{
	if (validate_map(argc, argv) == -1)
		return (1);
	return (0);
}