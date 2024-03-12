# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 15:16:43 by kmatjuhi          #+#    #+#              #
#    Updated: 2024/03/12 13:23:36 by kmatjuhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /Users/kmatjuhi/.brew/opt/glfw/lib 
# /usr/local/Cellar/glfw/3.4/lib

NAME	=	so_long
LIBMLX	=	./MLX42
LIBFT	=	./libft
LIBPF	=	./ft_printf

HEADERS	=	-I ./includes -I ${LIBMLX}/include -I ${LIBFT} -I ${LIBPF}
LIBGL	=	-lglfw -L"/Users/kmatjuhi/.brew/opt/glfw/lib"
LIBS	=	${LIBGL} ${LIBMLX}/libmlx42.a ${LIBFT}/libft.a ${LIBPF}/libftprintf.a
SRCS	=	main.c

OBJS	=	${SRCS:.c=.o}

all: libft libmlx libpf ${NAME}

libft:
	@${MAKE} -C ${LIBFT}

libmlx:
	@${MAKE} -C ${LIBMLX}

libpf:
	@${MAKE} -C ${LIBPF}

%.o: %.c
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS}
	@${CC} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	@rm -f ${OBJS}
	@${MAKE} -C ${LIBFT} clean
	@${MAKE} -C ${LIBMLX} clean
	@${MAKE} -C ${LIBPF} clean

fclean: clean
	@rm -f ${NAME}
	@${MAKE} -C ${LIBFT} fclean
	@${MAKE} -C ${LIBMLX} fclean
	@${MAKE} -C ${LIBPF} fclean
	
re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft