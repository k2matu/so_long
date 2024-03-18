/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:19:04 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/14 12:44:08 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define EMPTY_SPACE 0
# define WALL 1
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

typedef struct s_map
{
	int	collectible ;
	int	player ;
	int	exit ;
}	t_map;

typedef struct s_struct
{
	t_map	components ;
	int		moves ;
}	t_struct;

char	*read_file(char *str);
void	ft_error(char *str, char **map);

#endif