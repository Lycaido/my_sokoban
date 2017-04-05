/*
** enemy_bis.c for my_sokoban in /home/Rev/PSU_2016_my_sokoban/bonus
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Dec	14 18:34:58 2016 Roméo Nahon
** Last update	Wed Dec	14 18:34:58 2016 Roméo Nahon
*/

#include "include/my.h"

int	move_enemy_2_bi(t_vector *coord, int ch, t_temp *temp)
{
  if (coord->r == 0)
    if (COORD(M, J + 1, I) != '#' && COORD(M, J + 1, I) != 'X'
	&& COORD(M, J + 1, I) != '@' && coord->t == 0
	&& COORD(M, J + 1, I) != 'O')
      {
	mvwprintw(M, J += 1, I, "I");
	mvwprintw(M, J - 1, I, " ");
	if (COORD(M, J + 1, I) == '#' || COORD(M, J + 1, I) == 'X'
	    || COORD(M, J + 1, I) == '@' || COORD(M, J + 1, I) == 'I'
	    || COORD(M, J + 1, I) == 'O')
	  coord->t = 1;
	if (COORD(M, J - 1, I) == 'P' || COORD(M, J + 1, I) == 'P'
	    || COORD(M, J, I + 1) == 'P' || COORD(M, J, I - 1) == 'P')
	  box_loose(ch, coord, temp);
      }
    else if (COORD(M, J - 1, I) != '#' && COORD(M, J - 1, I) != 'X'
	     && COORD(M, J - 1, I) != '@' && coord->t == 1
	     && COORD(M, J - 1, I) != 'O')
      move_enemy_2bi_other(coord, ch, temp);
}
int	move_enemy_2bis(t_vector *coord, int ch, t_temp *temp)
{
  if (coord->r == 0)
    if (COORD(M, J, I + 1) != '#' && COORD(M, J, I + 1) != 'X'
	&& COORD(M, J, I + 1) != 'I'
	&& coord->c == 0 && COORD(M, J, I + 1) != 'O')
      {
	mvwprintw(M, J, I += 1, "I");
	mvwprintw(M, J, I - 1, " ");
	if (COORD(M, J, I + 1) == '#' || COORD(M, J, I + 1) == 'X'
	    || COORD(M, J, I + 1) == 'I' || COORD(M, J, I + 1) == 'O'
      || COORD(M, J, I + 1) == '@')
	  coord->c = 1;
	if (COORD(M, J - 1, I) == 'P' || COORD(M, J + 1, I) == 'P'
	    || COORD(M, J, I + 1) == 'P' || COORD(M, J, I - 1) == 'P')
	  box_loose(ch, coord, temp);
      }
    else if (COORD(M, J, I - 1) != '#' && COORD(M, J, I - 1) != 'X'
	     && COORD(M, J, I - 1) != 'I' && coord->c == 1
	     && COORD(M, J, I - 1) != 'O' && COORD(M, J, I - 1) != '@')
      move_enemy_2bis_other(coord, ch, temp);
}

int	move_enemy_2bis_other(t_vector *coord, int ch, t_temp *temp)
{
  mvwprintw(M, J, I -= 1, "I");
  mvwprintw(M, J, I + 1, " ");
  if (COORD(M, J, I - 1) == '#' || COORD(M, J, I - 1) == 'X'
      || COORD(M, J, I - 1) == 'I' || COORD(M, J, I - 1) == 'O'
      || COORD(M, J, I - 1) == '@')
    coord->c = 0;
  if (COORD(M, J - 1, I) == 'P' || COORD(M, J + 1, I) == 'P'
      || COORD(M, J, I + 1) == 'P' || COORD(M, J, I - 1) == 'P')
    box_loose(ch, coord, temp);
}
int	move_enemy_2bi_other(t_vector *coord, int ch, t_temp *temp)
{
  mvwprintw(M, J -= 1, I, "I");
  mvwprintw(M, J + 1, I, " ");
  if (COORD(M, J - 1, I) == '#' || COORD(M, J, I - 1) == 'P'
      || COORD(M, J - 1, I) == 'O' || COORD(M, J, I - 1) == '@')
    coord->t = 0;
  if (COORD(M, J - 1, I) == 'P' || COORD(M, J + 1, I) == 'P'
      || COORD(M, J, I + 1) == 'P' || COORD(M, J, I - 1) == 'P')
    box_loose(ch, coord, temp);
}
