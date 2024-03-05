# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 14:47:52 by kmatjuhi          #+#    #+#              #
#    Updated: 2024/03/05 15:23:11 by kmatjuhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c ft_printf_utils.c ft_putvalue.c

OFILES	=	$(SRCS:.c=.o)

CC		=	cc
RM		=	-rm -f
CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OFILES)

%.o: %.c
		$(CC) -c $(CFLAGS) $< -o $@
		ar rcs $(NAME) $@

clean:
	$(RM) $(OFILES)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
