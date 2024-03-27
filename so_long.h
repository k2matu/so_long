/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:19:04 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/27 18:17:10 by kmatjuhi         ###   ########.fr       */
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
	mlx_texture_t	*exit ;
	mlx_texture_t	*free ;
}	t_texture;

typedef struct s_image
{
	mlx_image_t	*wall ;
	mlx_image_t	*collectible ;
	mlx_image_t	*player ;
	mlx_image_t	*exit ;
	mlx_image_t	*free ;
}	t_image;

typedef struct s_struct
{
	t_map		comp ;
	int			player_y ;
	int			player_x ;
	int			exit_y ;
	int			exit_x ;
	int			moves ;
	int			rows ;
	int			columns ;
	char		**map;
	mlx_t		*mlx;
	t_texture	*texture;
	t_image		*img;
}	t_struct;

char	*read_file(char *str);
void	ft_error(t_struct *game, char *str, char **map);
void	validate_map(int argc, char **argv, t_struct *game);
char	**parse_map(char *str);
void	flood_fill(char **map, t_struct *game, int pos_x, int pos_y);
void	image_to_window(t_struct *game, char **map, int i, int j);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	draw_img_to_win(t_struct *game, mlx_image_t *image, int j, int i);

#endif