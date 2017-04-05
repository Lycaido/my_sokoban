/*
** enemy.c for my_sokoban in /home/Rev/PSU_2016_my_sokoban/bonus
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Tue Dec	13 15:57:40 2016 Roméo Nahon
** Last update	Tue Dec	13 15:57:40 2016 Roméo Nahon
*/

#include "include/my.h"

int	move_enemy(t_vector *coord, int ch, t_temp *temp)
{
  if (coord->r == 1)
    if (COORD(M, J, I + 1) != '#' && COORD(M, J, I + 1) != 'X'
	&& COORD(M, J, I + 1) != 'I' && coord->c == 0)
      {
	mvwprintw(M, J, I += 1, "@");
	mvwprintw(M, J, I - 1, " ");
	if (COORD(M, J, I + 1) == '#' || COORD(M, J, I + 1) == 'X'
	    && COORD(M, J, I + 1) != 'I' )
	  coord->c = 1;
	if (COORD(M, J, I + 1) == 'P')
	  box_loose(ch, coord, temp);
      }
    else if (COORD(M, J, I - 1) != '#' && COORD(M, J, I - 1) != 'X'
	     && COORD(M, J, I - 1) != 'I' && coord->c == 1)
      {
	mvwprintw(M, J, I -= 1, "@");
	mvwprintw(M, J, I + 1, " ");
	if (COORD(M, J, I - 1) == '#' || COORD(M, J, I - 1) == 'X'
	    && COORD(M, J, I - 1) != 'I')
	  coord->c = 0;
	if (COORD(M, J, I - 1) == 'P')
	  box_loose(ch, coord, temp);
      }
}
int	find_enemy(char *buffer, t_vector *coord)
{
  int	i;

  i = -1;
  coord->j = 0;
  coord->i = 0;
  coord->c = 0;
  while (buffer[++i] != '@')
    {
      coord->i += 1;
      if (buffer[i] == '\n')
	{
	  coord->i = 0;
	  coord->j += 1;
	}
    }
}
int	find_enemy_2(char *buffer, t_vector *coord)
{
  int	i;

  i = -1;
  coord->v = 0;
  coord->b = 7;
  coord->t = 1;
  while (buffer[++i] != 'I')
    {
      coord->b += 1;
      if (buffer[i] == '\n')
	{
	  coord->b = 7;
	  coord->v += 1;
	}
    }
}
int	move_enemy_2(t_vector *coord, int ch, t_temp *temp)
{
  if (coord->r == 1)
    if (COORD(M, V + 1, B) != '#' && COORD(M, V + 1, B) != 'X'
	&& COORD(M, V + 1, B) != '@' && coord->t == 0)
      {
	mvwprintw(M, V += 1, B, "I");
	mvwprintw(M, V - 1, B, " ");
	if (COORD(M, V + 1, B) == '#' || COORD(M, V + 1, B) == 'X'
	    && COORD(M, V + 1, B) != '@' && COORD(M, V + 1, B) != 'I')
	  coord->t = 1;
	if (COORD(M, V + 1, B) == 'P')
	  box_loose(ch, coord, temp);
      }
    else if (COORD(M, V - 1, B) != '#' && COORD(M, V - 1, B) != 'X'
	     && COORD(M, V - 1, B) != '@' && coord->t == 1)
      {
	mvwprintw(M, V -= 1, B, "I");
	mvwprintw(M, V + 1, B, " ");
	if (COORD(M, V - 1, B) == '#' || COORD(M, V - 1, B) == 'X'
	    && COORD(M, V + 1, B) != '@' && COORD(M, V - 1, B) != 'I')
	  coord->t = 0;
	if (COORD(M, V - 1, B) == 'P')
	  box_loose(ch, coord, temp);
      }
}
