/*
** state.c for my_sokoban in /home/Rev/PSU_2016_my_sokoban
**
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
**
** Started on	Sun Dec	11 12:21:28 2016 Roméo Nahon
** Last update	Sun Dec	11 12:21:28 2016 Roméo Nahon
*/

#include "include/my.h"

int	loose_next(t_vector *coord)
{
  if (COORD(M, Y, X - 2) == '#' && COORD(M, Y + 1, X + 1) == '#'
      && COORD(M, Y, X -1) == 'X')
    return (1);
  else if (COORD(M, Y - 2, X) == '#' && COORD(M, Y - 1, X + 1) == '#'
	   && COORD(M, Y - 1, X) == 'X')
    return (1);
  else if (COORD(M, Y - 2, X) == '#' && COORD(M, Y - 1, X - 1) == '#'
	   && COORD(M, Y - 1, X) == 'X')
    return (1);
  else if (COORD(M, Y, X - 2) == '#' && COORD(M, Y - 1, X - 1) == '#'
	   && COORD(M, Y, X - 1) == 'X')
    return (1);
  return (0);
}
int	loose(t_vector *coord)
{
  if (COORD(M, Y + 2, X) == '#' && COORD(M, Y + 1, X + 1) == '#'
      && COORD(M, Y + 1, X) == 'X')
    return (1);
  else if (COORD(M, Y + 2, X) == '#' && COORD(M, Y + 1, X - 1) == '#'
	   && COORD(M, Y + 1, X) == 'X')
    return (1);
  else if (COORD(M, Y, X + 2) == '#' && COORD(M, Y - 1, X + 1) == '#'
	   && COORD(M, Y, X + 1) == 'X')
    return (1);
  else if (loose_next(coord) == 1)
    return (1);
  return (0);
}
int	won(t_vector *coord)
{
  if (coord->nb_x == 0)
    return (1);
  return (0);
}
t_get	get_size(char *buffer)
{
  t_get	get;
  int	i;

  i = -1;
  get.y = 0;
  get.x = 0;
  while (buffer[++i] != '\0')
    {
      get.x += 1;
      if (buffer[i] == '\n')
	{
	  get.x = 0;
	  get.y += 1;
	}
    }
  return (get);
}
void	resize(char *buffer)
{
  WINDOW	*sub;
  t_get		get;
  int		x;
  int		y;
  int		size;
  char		*msg;

  msg = my_strdup(MSG);
  size = my_strlen(msg);
  get = get_size(buffer);
  getmaxyx(stdscr, y, x);
  while (y < get.y || x < get.x)
    {
      clear();
      sub = subwin(stdscr, 5, 30, LINES/2, COLS/2 - (size/5));
      mvwprintw(sub, 1, 1, msg);
      if (getch() != 410)
	break;
      if (getch() == 'q')
	{
	  endwin();
	  exit(EXIT_SUCCESS);
	}
    }
}
