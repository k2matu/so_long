/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:53:20 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/18 11:53:34 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parse_map(char *str)
{
	char	**two_d_map;
	char	*map;

	map = read_file(str);
	two_d_map = ft_split(map, '\n');
	free(map);
	return (two_d_map);
}
