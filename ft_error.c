/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:21:33 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/27 20:01:01 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_struct *game, char *str, char **map)
{
	ft_free_arr(map);
	ft_putendl_fd("Error", 1);
	ft_putstr_fd(str, 1);
	if (game)
	{
		mlx_delete_image(game->mlx, game->img->wall);
		mlx_delete_image(game->mlx, game->img->collectible);
		mlx_delete_image(game->mlx, game->img->player);
		mlx_delete_image(game->mlx, game->img->exit);
		mlx_delete_image(game->mlx, game->img->free);
	}
	exit(1);
}
