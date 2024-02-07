INCLUDES	=	-I/opt/X11/include -Imlx

NAME		=	so_long

SRCS		=	so_long.c

OBJS		=	$(SRCS:.c=.o)

CC			=	cc
RM			=	-rm -f
# CFLAGS		=	-Wall -Werror -Wextra

MLX_FLAGS	=	-Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME) $(OBJS)
	
re: fclean all

.PHONY: all clean fclean 