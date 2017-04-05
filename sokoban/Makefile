##
## Makefile for bootstrap in /home/Rev/CSFML/bootstrap
## 
## Made by Roméo Nahon
## Login	 <Rev@epitech.net>
## 
## Started on	Thu Nov	10 12:12:07 2016 Roméo Nahon
## Last update	Thu Nov	10 12:12:07 2016 Roméo Nahon
##

SRC = 	my_sokoban.c 		\
		manager.c 			\
		state.c 			\
		player.c			\
		moving.c 			\
		box.c 				\
		help.c				\
		enemy.c				\
		w_o_l.c				\
		enemy_bis.c			\
		init.c				\

OBJ = $(SRC:.c=.o)

NAME = my_sokoban

all: $(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -Llib/my -lncurses -lmy -o $(NAME)
	rm -f $(OBJ)

val: $(SRC)
	gcc -g3 $(SRC) -Llib/my -lmy -o $(NAME) -lncurses
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *~
	rm -f *#

re: fclean all
