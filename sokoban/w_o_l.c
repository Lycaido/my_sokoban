/*
** w_o_l.c for my_sokoban in /home/Rev/PSU_2016_my_sokoban/bonus
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Dec	12 18:20:00 2016 Roméo Nahon
** Last update	Mon Dec	12 18:20:00 2016 Roméo Nahon
*/

#include "include/my.h"

int	w_o(t_vector *coord, int ch, t_temp *temp)
{
  if (won(coord) == 1)
  {
    box_win(ch, coord, temp);
    return (2);
  }
  return (0);
}
int	o_l(t_vector *coord, int ch, t_temp *temp)
{
  if (loose(coord) == 1)
  {
    box_loose(ch, coord, temp);
    return (1);
  }
}

int pos_o(t_vector *coord)
{
  if (COORD(M, Y_, X_) != 'O'
    && COORD(M, Y_, X_) != 'P'
    & COORD(M, Y_, X_) != 'X')
  {
    mvwprintw(M, Y_, X_, "O");
    if (COORD(M, Y_, X_) == 'X')
    {
      coord->x_tmp = X_;
      coord->y_tmp = Y_;
    }
  }
}

void  stock(t_vector *coord)
{
  display_score(coord);
  pos_o(coord);
}