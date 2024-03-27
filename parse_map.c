/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:53:20 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/27 16:43:13 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_new_lines(char **two_d_map, char *map)
{
	int	i;
	int	count_new_lines;

	i = 0;
	count_new_lines = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			count_new_lines++;
		i++;
	}
	i = 0;
	while (two_d_map[i] != NULL)
		i++;
	if (i != (count_new_lines + 1))
		ft_error(NULL, "No empty lines allowed", two_d_map);
}

char	**parse_map(char *str)
{
	char	**two_d_map;
	char	*map;

	map = read_file(str);
	two_d_map = ft_split(map, '\n');
	if (!two_d_map)
		ft_error(NULL, "Malloc error in ft_split", NULL);
	check_new_lines(two_d_map, map);
	free(map);
	return (two_d_map);
}
