/*
** my.h for bootstrap in /home/Rev/CSFML/bootstrap
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Thu Nov	10 10:15:08 2016 Roméo Nahon
** Last update	Thu Nov	10 10:15:08 2016 Roméo Nahon
*/

#ifndef MY_H
# define MY_H

#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MSG "/!\\ Terminal too little /!\\\npress 'q' to quit\nand restart the program"
#define MSG1 "Program by Roméo Nahon, This game is the Sokoban."
#define MSG2 "A japanese game where the aim is to move box"
#define MSG3 "To play move with directionnal arrow"
#define MSG4 "To return to the menu press 'r'"
#define Y coord->y
#define X coord->x
#define J coord->j
#define I coord->i
#define V coord->v
#define B coord->b
#define M coord->map
#define X_ coord->x_
#define Y_ coord->y_
#define COORD(M, y, x) mvwinch(M,y,x)

int 	my_strlen(char *str);
int		count_x(char *buffer);
void 	my_printf(char *str, ...);
char 	*my_strdup(char *str);

typedef struct 	s_temp
{
	int			x;
	int			y;
}				t_temp;

typedef struct  s_vector
{
	int			x;
	int			y;
	int			j;
	int			i;
	int			c;
	int 		c1;
	int			c2;
	int			v;
	int			b;
	int			t;
	int			x_;
	int			y_;
	int			r;
	int			x_o;
	int			y_o;
	int			x_tmp;
	int 		y_tmp;
	int 		nb_x;
	int 		score;
	int			defense;
	char		*buffer;
	WINDOW		*map;
} 				t_vector;

typedef struct 	s_get
{
	int 		x;
	int 		y;
}			    t_get;

typedef struct 	s_menu
{
	int			x;
	int			y;
	int			i;
	WINDOW		*start;
}				t_menu;

void  		find_arobase(char *buffer, t_vector *coord);
void  		protect_player(t_vector *coord, int ch);
void  		find_o(char *buffer, t_vector *coord);
void  		stock(t_vector *coord);
int			set_coord_y(t_vector *coord, int valuey, int valuex);
int			set_coord_x(t_vector *coord, int valuey, int valuex);
int 		pos_o(t_vector *coord);
int 		move_enemy_2bi_other(t_vector *coord, int ch, t_temp *temp);
int 		move_enemy_2bis_other(t_vector *coord, int ch, t_temp *temp);
void 		select_secret(t_vector *coord, t_temp *temp, int ch);
int			move_enemy_2_bi(t_vector *coord, int ch, t_temp *temp);
int			move_enemy_2bis(t_vector *coord, int ch, t_temp *temp);
int 		first_map(t_vector *coord, t_temp *temp, t_menu *menu);
int			display_secret(t_vector *coord, t_temp *temp, t_menu *menu);
int			display_tuto(t_vector *coord);
int 		find_enemy_2(char *buffer, t_vector *coord);
int			move_enemy_2(t_vector *coord, int ch, t_temp *temp);
int			move_enemy(t_vector *coord, int ch, t_temp *temp);
int 		find_enemy(char *buffer, t_vector *coord);
int			display_map(t_vector *coord);
int			display_menu(t_menu *menu);
int 		help(t_menu *menu, t_vector *coord, t_temp *temp, int ch);
int			key_menu(int ch, t_menu *menu);
int			set_coord(t_vector *coord, t_temp *temp, char *buffer);
int 		choice(t_menu *menu, t_vector *coord, t_temp *temp, int ch);
int			happy_meal(t_vector *coord, t_temp *temp);
int			box_loose(int ch, t_vector *coord, t_temp *temp);
int			box_win(int ch, t_vector *coord, t_temp *temp);
int			reset_final(t_temp *temp, t_vector *coord, char *buffer, int ch);
int			loose_next(t_vector *coord);
int			loose(t_vector *coord);
int			manager(char *buffer, t_vector *coord, t_temp *temp, int ch);
int			won(t_vector *coord);
int			w_o(t_vector *coord, int ch, t_temp *temp);
int			o_l(t_vector *coord, int ch, t_temp *temp);
int			key_up(t_vector *coord);
int			key_down(t_vector *coord);
int			key_left(t_vector *coord);
int			key_right(t_vector *coord);
int			move_player(t_vector *coord, int ch);
int			find_player(char *buffer, t_vector *coord);
int			display_score(t_vector *coord);
void 		resize(char *buffer);
t_get 		get_size(char *buffer);


#endif /* MY_H */