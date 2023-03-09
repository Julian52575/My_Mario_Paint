##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## it makes files
##

SRC = 	$(wildcard src/*.c src/*/*.c src/*/*/*.c lib/*/*.c lib/*/*/*.c)

OBJ = $(SRC:.c=.o)

CFLAGS += -g -Wall -Wextra -lmy -ldl -I./includes -L./lib/my

CSFlags += -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

NAME = "my_paint"

$(NAME): $(OBJ)
	gcc -g -o $(NAME) $(OBJ) -Wl,--copy-dt-needed-entries $(CSFlags)

all:     $(NAME)

clear:
	make
	clear
	echo "Done !"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
