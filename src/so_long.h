/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:19:04 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/13 13:58:49 by kmatjuhi         ###   ########.fr       */
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

char	*read_file(char *str);

#endif