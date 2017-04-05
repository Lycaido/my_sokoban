/*
** help.c for my_sokoban in /home/Rev/PSU_2016_my_sokoban/bonus
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Dec	12 20:45:59 2016 Roméo Nahon
** Last update	Mon Dec	12 20:45:59 2016 Roméo Nahon
*/

#include "include/my.h"

int	help(t_menu *menu, t_vector *coord, t_temp *temp, int ch)
{
  WINDOW	*help;
  int		x;
  int		y;

  wclear(menu->start);
  wrefresh(menu->start);
  while (1)
    {
      help = subwin(stdscr, 8, 62, LINES/2, (COLS/2 - 34));
      clear();
      wclear(help);
      box(help, ACS_VLINE, ACS_HLINE);
      mvwprintw(help, 1, 5, MSG1);
      mvwprintw(help, 2, 5, MSG2);
      mvwprintw(help, 3, 5, "on a right point, represent by 'O'");
      mvwprintw(help, 4, 5, MSG3);
      mvwprintw(help, 6, 5, MSG4);
      if ((ch = getch()) == 'r')
	{
	  wclear(help);
	  wrefresh(help);
	  happy_meal(coord, temp);
	}
      wrefresh(help);
    }
}
void	select_secret(t_vector *coord, t_temp *temp, int ch)
{
  if (coord->r == 1)
    {
      move_enemy(coord, ch, temp);
      move_enemy_2(coord, ch, temp);
    }
  else if (coord->r == 0)
    {
      move_enemy_2_bi(coord, ch, temp);
      move_enemy_2bis(coord, ch, temp);
    }
}
int	display_menu(t_menu *menu)
{
  menu->y = LINES/2 + 1;
  menu->x = COLS/2 - 4;
  menu->i = 0;
  clear();
  attron(A_BOLD);
  menu->start = subwin(stdscr, 6, 14, LINES/2, (COLS/2 - 5));
  wclear(menu->start);
  mvwprintw(menu->start, 1, 4, "Start");
  mvwprintw(menu->start, 2, 4, "Secret");
  mvwprintw(menu->start, 3, 4, "Help");
  mvwprintw(menu->start, 4, 4, "quit");
  mvprintw(menu->y, menu->x, "->");
  mvprintw(menu->y, menu->x + 10, "<-");
  box(menu->start, ACS_VLINE, ACS_HLINE);
}
