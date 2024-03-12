/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:31:32 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/12 14:01:14 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *read_file(char *str)
{
	int		fd;
	int		sz;
	char	c;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit(1);
	while(read(fd, &c, ))
}

char	**parse_map(char *str)
{
	char	*map;

	printf("%s", map);
	return (NULL);

}

int	validate_map(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		return (-1);

	map = parse_map(argv[1]);
	return (0);
}

int	main(int argc, char **argv)
{
	if (validate_map(argc, argv) == -1)
		return (1);
	return (0);
}