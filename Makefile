# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 15:16:43 by kmatjuhi          #+#    #+#              #
#    Updated: 2024/03/18 10:26:54 by kmatjuhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /Users/$(USER)/.brew/opt/glfw/lib/
# /usr/local/Cellar/glfw/3.4/lib

NAME = so_long

LIBFT = ./libft/libft.a

MLX42 = ./MLX42/build/libmlx42.a

SRCS = ./src/main.c ./src/read_file.c ./src/ft_error.c ./src/validate_map.c

# CFLAGS = -g -Wall -Wextra -Werror

MLX42FLAGS = -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

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