# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 15:16:43 by kmatjuhi          #+#    #+#              #
#    Updated: 2024/03/26 13:42:08 by kmatjuhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /Users/$(USER)/.brew/opt/glfw/lib/
# /usr/local/Cellar/glfw/3.4/lib

NAME = so_long

LIBFT = ./libft/libft.a

MLX42 = ./MLX42/build/libmlx42.a

SRCS = main.c \
		read_file.c \
		ft_error.c \
		validate_map.c \
		parse_map.c \
		flood_fill.c \
		graphic.c \
		move.c

CFLAGS = -g -Wall -Wextra -Werror

MLX42FLAGS = -Iinclude -lglfw -L"/usr/local/Cellar/glfw/3.4/lib"

all: ${NAME}

${NAME}: ${SRCS} $(LIBFT) $(MLX42)
	cc $(CFLAGS) $^ -framework Cocoa -framework OpenGL -framework IOKit -o $@ $(LIBFT) $(MLX42) $(MLX42FLAGS)

$(LIBFT):
	make -C libft/

$(MLX42):
	cd MLX42 && cmake -B build
	cd MLX42 && cmake --build build -j4
	make -C MLX42/build -j4

clean:
	make clean -C libft
	make clean -C MLX42/build

fclean: clean
	rm -f ${NAME} ${NAME_BONUS}
	make fclean -C libft
	make clean -C MLX42/build

re: fclean all

.PHONY: all clean fclean re