/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:19:04 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/27 14:28:29 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include "./MLX42/include/MLX42/MLX42.h"

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
	int			exit_pos_y ;
	int			exit_pos_x ;
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
void	get_texture(t_struct *game);
void	texture_to_image(t_struct *game);
void	image_to_window(t_struct *game, char **map, int i, int j);
void	my_keyhook(mlx_key_data_t keydata, void *param);

#endif