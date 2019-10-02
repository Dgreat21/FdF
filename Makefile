CC = gcc

CFLAGS = -Wall -Wextra -Werror -c -I ./includes/

SRC_FC =        *.c

SRC_FO =        *.o

NAME = fdf

all: $(NAME)

$(NAME):
		cc -o $(NAME) -I /usr/local/include fdf.c libft/libft.a main.c struct.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

hand:
		gcc -o hand handler.c libft/libft.a

test:
		./hand example/maps/42.fdf

clean:
		@/bin/rm -f $(SRC_FO)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all

check: re
		@/bin/rm -f $(SRC_FO)

fuck:
		cc -Wall -Wextra -Werror -o $(NAME) -I /usr/local/include fdf.c libft/libft.a main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit


