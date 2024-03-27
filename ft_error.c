/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:21:33 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/27 16:45:51 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_struct *game, char *str, char **map)
{
	ft_free_arr(map);
	ft_putendl_fd("Error", 1);
	ft_putstr_fd(str, 1);
	if (game)
		mlx_terminate(game->mlx);
	exit(1);
}
