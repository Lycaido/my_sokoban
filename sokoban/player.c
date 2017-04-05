/*
** player.c for my_sokoban in /home/Rev/PSU_2016_my_sokoban
**
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
**
** Started on	Sat Dec	10 15:16:52 2016 Roméo Nahon
** Last update	Sat Dec	10 15:16:52 2016 Roméo Nahon
*/

#include "include/my.h"

int	find_player(char *buffer, t_vector *coord)
{
  int	i;

  i = -1;
  coord->y = 0;
  coord->x = 0;
  while (buffer[++i] != 'P')
  {
    coord->x += 1;
    if (buffer[i] == '\n')
    {
     coord->x = 0;
     coord->y += 1;
   }
 }
}

int	move_player(t_vector *coord, int ch)
{
  keypad(stdscr, TRUE);
  if (ch == KEY_UP)
    key_up(coord);
  else if (ch == KEY_DOWN)
    key_down(coord);
  else if (ch == KEY_LEFT)
    key_left(coord);	
  else if (ch == KEY_RIGHT)
    key_right(coord);
}
void  find_o(char *buffer, t_vector *coord)
{
  int   i;

  i = -1;
  coord->y_o = 0;
  coord->x_o = 0;
  while (buffer[++i] != 'O')
  {
    coord->x_o += 1;
    if (buffer[i] == '\n')
    {
      coord->x_o = 0;
      coord->y_o += 1;
    }
  }
}

void  protect_player(t_vector *coord, int ch)
{
  if (coord->defense == 1 && coord->r == 0)
  {
    mvwprintw(M, Y, X, "@");
    if (ch == ' ')
      coord->defense = 0;
  }
  else if (coord->defense == 0 && coord->r == 0)
  {
    mvwprintw(M, Y, X, "P");
    move_player(coord, ch);
    if (ch == ' ')
    {
      beep();
      coord->defense = 1;
    }
  }
  if (coord->r == 1)
    move_player(coord, ch);
}

void  find_arobase(char *buffer, t_vector *coord)
{
 int  i;

 i = -1;
 coord->y = 0;
 coord->x = 0;
 while (buffer[++i] != '@')
 {
  coord->x += 1;
  if (buffer[i] == '\n')
  {
   coord->x = 0;
   coord->y += 1;
 }
}
mvwprintw(M, Y, X, " ");
}