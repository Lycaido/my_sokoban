/*
** moving.c for my_sokoban in /home/Rev/PSU_2016_my_sokoban
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Dec	10 16:05:31 2016 Roméo Nahon
** Last update	Sat Dec	10 16:05:31 2016 Roméo Nahon
*/

#include "include/my.h"

int	key_up(t_vector *coord)
{
  if (COORD(M, Y - 1, X) != '#' && COORD(M, Y - 1, X) != 'X'
    && COORD(M, Y - 1, X) != 'I' && COORD(M, Y - 1, X) != '@')
  {
    set_coord_x(coord, Y - 1, X);
    set_coord_y(coord, Y - 1, X);
    mvwprintw(coord->map, Y, X, " ");
    mvwprintw(coord->map, Y -= 1, X, "P");
    coord->score += 1;
    stock(coord);
  }
  else if (COORD(M, Y - 1, X) == 'X' && COORD(M, Y - 2, X) != '#'
    && COORD(M, Y - 2, X) != 'X' && COORD(M, Y - 2, X) != '@'
    && COORD(M, Y - 2, X) != 'I')
  {
    set_coord_x(coord, Y - 2, X);
    set_coord_y(coord, Y - 2, X);
    if (COORD(M, Y - 2, X) == 'O')
     coord->nb_x -= 1;
   mvwprintw(coord->map, Y - 2, X, "X");
   mvwprintw(coord->map, Y , X, " ");
   mvwprintw(coord->map, Y -= 1, X, "P");
   coord->score += 1;
   stock(coord);
 }
}

int	key_down(t_vector *coord)
{
  if (COORD(M, Y + 1, X) != '#' && COORD(M, Y + 1, X) != 'X'
    && COORD(M, Y + 1, X) != 'I' && COORD(M, Y + 1, X) != '@')
  {
    set_coord_x(coord, Y + 1, X);
    set_coord_y(coord, Y + 1, X);
    mvwprintw(coord->map, Y, X, " ");
    mvwprintw(coord->map, Y += 1, X, "P");
    coord->score += 1;
    stock(coord);
  }
  else if (COORD(M, Y + 1, X) == 'X' && COORD(M, Y + 2, X) != '#'
    && COORD(M, Y + 2, X) != 'X' && COORD(M, Y + 2, X) != '@'
    && COORD(M, Y + 2, X) != 'I')
  {
    set_coord_x(coord, Y + 2, X);
    set_coord_y(coord, Y + 2, X);
    if (COORD(M, Y + 2, X) == 'O')
     coord->nb_x -= 1;
   mvwprintw(coord->map, Y + 2, X, "X");
   mvwprintw(coord->map, Y, X, " ");
   mvwprintw(coord->map, Y += 1, X, "P");
   coord->score += 1;
   stock(coord);
 }
}

int	key_left(t_vector *coord)
{
  if (COORD(M, Y, X - 1) != '#' && COORD(M, Y, X - 1) != 'X'
    && COORD(M, Y, X - 1) != 'I' && COORD(M, Y, X - 1) != '@')
  {
    set_coord_x(coord, Y, X - 1);
    set_coord_y(coord, Y, X - 1);
    mvwprintw(coord->map, Y, X, " ");
    mvwprintw(coord->map, Y, X -= 1, "P");
    coord->score += 1;
    stock(coord);
  }
  else if (COORD(M, Y, X - 1) == 'X' && COORD(M, Y, X - 2) != '#'
    && COORD(M, Y, X - 2) != 'X' && COORD(M, Y, X - 2) != '@'
    && COORD(M, Y, X - 2) != 'I')
  {
    X_ = set_coord_x(coord, Y, X - 2);
    Y_ = set_coord_y(coord, Y, X - 2);
    if (COORD(M, Y, X - 2) == 'O')
     coord->nb_x -= 1;
   mvwprintw(coord->map, Y, X - 2, "X");
   mvwprintw(coord->map, Y, X, " ");
   mvwprintw(coord->map, Y, X -= 1, "P");
   coord->score += 1;
   stock(coord);
 }
}

int	key_right(t_vector *coord)
{
  if (COORD(M, Y, X + 1) != '#' && COORD(M, Y, X + 1) != 'X'
    && COORD(M, Y, X + 1) != 'I' && COORD(M, Y, X + 1) != '@')
  {
    set_coord_x(coord, Y, X + 1);
    set_coord_y(coord, Y, X + 1);
    mvwprintw(coord->map, Y, X, " ");
    mvwprintw(coord->map, Y, X += 1, "P");
    coord->score += 1;
    stock(coord);
  }
  else if (COORD(M, Y, X + 1) == 'X' && COORD(M, Y, X + 2) != '#'
    && COORD(M, Y, X + 2) != 'X' && COORD(M, Y, X + 2) != '@'
    && COORD(M, Y, X + 2) != 'I')
  {
    set_coord_x(coord, Y, X + 2);
    set_coord_y(coord, Y, X + 2);
    if (COORD(M, Y, X + 2) == 'O')
     coord->nb_x -= 1;
   mvwprintw(coord->map, Y, X + 2, "X");
   mvwprintw(coord->map, Y, X, " ");
   mvwprintw(coord->map, Y, X += 1, "P");
   coord->score += 1;
   stock(coord);
 }
}

int	key_menu(int ch, t_menu *menu)
{
  keypad(stdscr, TRUE);
  if (ch == KEY_UP && menu->i <= 3 && menu->i > 0)
  {
    menu->y -= 1;
    mvprintw(menu->y, menu->x, "->");
    mvprintw(menu->y, menu->x + 10, "<-");
    mvprintw(menu->y + 1, menu->x, "  ");
    mvprintw(menu->y + 1, menu->x + 10, "  ");
    menu->i -= 1;
  }
  else if (ch == KEY_DOWN && menu->i >= 0 && menu->i < 3)
  {
    menu->y += 1;
    mvprintw(menu->y, menu->x, "->");
    mvprintw(menu->y, menu->x + 10, "<-");
    mvprintw(menu->y - 1, menu->x, "  ");
    mvprintw(menu->y - 1, menu->x + 10, "  ");
    menu->i += 1;
  }
}
