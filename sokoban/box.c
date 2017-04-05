/*
** loose.c for my_sokoban in /home/Rev/PSU_2016_my_sokoban/bonus
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Dec	12 16:49:29 2016 Roméo Nahon
** Last update	Mon Dec	12 16:49:29 2016 Roméo Nahon
*/

#include "include/my.h"

int	box_loose(int ch, t_vector *coord, t_temp *temp)
{
  WINDOW	*lost;
  int		c;

  clear();
  attron(A_BOLD);
  while (1)
    {
      lost = subwin(stdscr, 5, 35, LINES/2, (COLS/2 - 13));
      clear();
      wclear(lost);
      box(lost, ACS_VLINE, ACS_HLINE);
      mvwprintw(lost, 1, 10, "Lost !");
      mvwprintw(lost, 2, 5, "Your score is : %d moves", coord->score);
      mvwprintw(lost, 3, 5, "Press 'r' to go to menu");
      if ((c = getch()) == 'r')
	{
	  wclear(lost);
	  wrefresh(lost);
	  set_coord(coord, temp, coord->buffer);
	  attroff(A_BOLD);
	  happy_meal(coord, temp);
	}
      refresh();
      wrefresh(lost);
    }
}

int	box_win(int ch, t_vector *coord, t_temp *temp)
{
  WINDOW	*win;
  int		c;

  clear();
  attron(A_BOLD);
  while (1)
    {
      win = subwin(stdscr, 5, 35, LINES/2, (COLS/2 - 13));
      box(win, ACS_VLINE, ACS_HLINE);
      mvwprintw(win, 1, 10, "Won !");
      mvwprintw(win, 2, 5, "Your score is : %d moves", coord->score);
      mvwprintw(win, 3, 5, "Press 'r' to go to menu");
      if ((c = getch()) == 'r')
	{
	  wclear(win);
	  wrefresh(win);
	  set_coord(coord, temp, coord->buffer);
	  attroff(A_BOLD);
	  happy_meal(coord, temp);
	}
    }
}

int	choice(t_menu *menu, t_vector *coord, t_temp *temp, int ch)
{
  if (ch == '\n' && menu->i == 0)
    first_map(coord, temp, menu);
  else if (ch == '\n' && menu->i == 1)
    display_secret(coord, temp, menu);
  else if (ch == '\n' && menu->i == 2)
    help(menu, coord, temp, ch);
  else if (ch == '\n' && menu->i == 3)
    {
      endwin();
      exit(EXIT_SUCCESS);
    }
  return (0);
}
int	display_secret(t_vector *coord, t_temp *temp, t_menu *menu)
{
  char	buffer[10000];
  int	fd;
  int	ch;

  coord->r = 0;
  fd = open("./map3.wf", O_RDONLY);
  if (fd == -1)
    exit(84);
  read(fd, buffer, 10000);
  coord->buffer = buffer;
  set_coord(coord, temp, coord->buffer);
  wclear(menu->start);
  wrefresh(menu->start);
  attroff(A_BOLD);
  if ((manager(coord->buffer, coord, temp, ch)) == 1)
    {
      endwin();
      return (1);
    }
}
int	happy_meal(t_vector *coord, t_temp *temp)
{
  t_menu	*menu;
  int		ch;

  menu = malloc(sizeof(t_menu));
  display_menu(menu);
  while ((ch = getch()))
    {
      key_menu(ch, menu);
      if (choice(menu, coord, temp, ch) == 1)
	return (1);
    }
}
