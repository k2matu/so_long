/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:19:04 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/22 12:49:04 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define SIZE 35

typedef struct s_map
{
	int	collectible ;
	int	player ;
	int	exit ;
}	t_map;

typedef struct s_texture
{
	mlx_texture_t	*wall ;
	mlx_texture_t	*collectible ;
	mlx_texture_t	*player ;
	mlx_texture_t	*exit_open ;
	mlx_texture_t	*exit_closed ;
	mlx_texture_t	*free ;
}	t_texture;

typedef struct s_image
{
	mlx_image_t	*wall ;
	mlx_image_t	*collectible ;
	mlx_image_t	*player ;
	mlx_image_t	*exit_open ;
	mlx_image_t	*exit_closed ;
	mlx_image_t	*free ;
}	t_image;

typedef struct s_struct
{
	t_map		comp ;
	int			player_pos_y ;
	int			player_pos_x ;
	int			moves ;
	int			rows ;
	int			columns ;
	char		**map;
	mlx_t		*mlx;
	t_texture	*texture;
	t_image		*img;
}	t_struct;

char	*read_file(char *str);
void	ft_error(char *str, char **map);
int		validate_map(int argc, char **argv, t_struct *game);
char	**parse_map(char *str);
void	flood_fill(char **map, t_struct *game, int pos_x, int pos_y);
void	print_map(char **map);
void	get_texture(t_struct *game);
void	texture_to_image(t_struct *game);
void	image_to_window(t_struct *game, char **map);
void	my_keyhook(mlx_key_data_t keydata, void *param);

#endif