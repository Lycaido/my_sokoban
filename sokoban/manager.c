/*
** display.c for my_sokoban in /home/Rev/PSU_2016_my_sokoban
**
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
**
** Started on	Sat Dec	10 12:45:48 2016 Roméo Nahon
** Last update	Sat Dec	10 12:45:48 2016 Roméo Nahon
*/

#include "include/my.h"

int	display_map(t_vector *coord)
{
  t_get	get;

  get = get_size(coord->buffer);
  coord->map = subwin(stdscr, get.y + 4, get.x + 4, LINES/2, (COLS/2 - 15));
  mvwprintw(coord->map, 0, 0, coord->buffer);
  find_enemy(coord->buffer, coord);
  find_enemy_2(coord->buffer, coord);
  wrefresh(coord->map);
}
int	manager(char *buffer, t_vector *coord, t_temp *temp, int ch)
{
  display_map(coord);
  display_tuto(coord);
  display_score(coord);
  while (1)
  {
      halfdelay(1);
      if (o_l(coord, ch, temp) == 1)
       return (1);
     else if (w_o(coord, ch, temp) == 2)
       return (1);
     if ((ch = getch()) == 'q' || ch == 'Q' )
     {
       clear();
       set_coord(coord, temp, buffer);
       coord->buffer = buffer;
       happy_meal(coord, temp);
     }
     select_secret(coord, temp, ch);
     protect_player(coord, ch);
     wrefresh(coord->map);
     resize(buffer);
   }
   return (0);
 }
 int	reset_final(t_temp *temp, t_vector *coord, char *buffer, int ch)
 {
  clear();
  find_player(buffer, coord);
  find_enemy(buffer, coord);
  find_enemy_2(coord->buffer, coord);
  coord->nb_x = count_x(buffer);
}
int		display_score(t_vector *coord)
{
  WINDOW	*score;
  int		c;

  attron(A_BOLD);
  score = subwin(stdscr, 3, 25, LINES/2 - 4, (COLS/2 - 11));
  box(score, ACS_VLINE, ACS_HLINE);
  mvwprintw(score, 1, 5, "Score: %d moves", coord->score);
  wrefresh(score);
  attroff(A_BOLD);
}
int		display_tuto(t_vector *coord)
{
  WINDOW	*score;
  int		c;

  attron(A_BOLD);
  score = subwin(stdscr, 7, 38, LINES/2 + 13, (COLS/2 - 18));
  box(score, ACS_VLINE, ACS_HLINE);
  mvwprintw(score, 1, 1, "To move use directional arrow.");
  mvwprintw(score, 2, 1, "Put 'X' on '0'. You are 'P'.");
  mvwprintw(score, 3, 1, "Becareful, don't touch '@' or 'I' !");
  mvwprintw(score, 4, 1, "Use 'q' to quit.");
  wrefresh(score);
  attroff(A_BOLD);
}
