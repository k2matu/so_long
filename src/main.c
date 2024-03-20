/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:31:32 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/20 11:26:40 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	static t_struct	game;
	char			**map;

	game = (t_struct){{0}, 0};
	if (!validate_map(argc, argv, &game))
		return (1);
	map = parse_map(argv[1]);
	// mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "so_long", 1);
	// mlx_image_t *img = mlx_new_image(mlx, 50, 50);
	// ft_memset(img->pixels, 100, img->width * img->height * sizeof(int32_t));
	// mlx_image_to_window(mlx, img, 50, 50);
	// mlx_loop(mlx);

	return (0);
}