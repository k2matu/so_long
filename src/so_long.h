/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:19:04 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/19 11:31:32 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define EMPTY_SPACE '0'
# define WALL '1'
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
	t_map	comp ;
	int		player_pos_y ;
	int		player_pos_x ;
	int		moves ;
}	t_struct;

char	*read_file(char *str);
void	ft_error(char *str, char **map);
int		validate_map(int argc, char **argv, t_struct *game);
char	**parse_map(char *str);
void	flood_fill(char **map, t_struct *game, int pos_x, int pos_y);
void	print_map(char **map);

#endif