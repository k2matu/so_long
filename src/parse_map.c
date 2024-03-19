/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:53:20 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/19 12:13:18 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_new_lines(char **two_d_map, char *map)
{
	int	i;
	int	count_new_lines;

	i = -1;
	count_new_lines = 0;
	while (map[i])
	{
		printf("%c", map[i]);
		if (map[i] == '\n')
			count_new_lines++;
		i++;
	}
	printf("count lines %d", count_new_lines);
}

char	**parse_map(char *str)
{
	char	**two_d_map;
	char	*map;

	map = read_file(str);
	two_d_map = ft_split(map, '\n');
	check_new_lines(two_d_map, map);
	free(map);
	return (two_d_map);
}
