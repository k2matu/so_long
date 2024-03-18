/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:51:21 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/14 13:01:55 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_file(char *str)
{
	int		fd;
	int		sz;
	char	c;
	char	*map;

	sz = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error("Open file error", NULL);
	while (read(fd, &c, 1) == 1)
		sz++;
	close(fd);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error("Open file error", NULL);
	map = malloc(sizeof(char) * (sz + 1));
	if (!map)
		ft_error("Malloc error", NULL);
	read(fd, map, sz);
	map[sz] = '\0';
	return (map);
}
