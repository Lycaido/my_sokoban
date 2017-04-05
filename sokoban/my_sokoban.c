/*
** my_sokoban.c for my_sokoban in /home/Rev/PSU_2016_my_sokoban
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Dec	7 14:08:10 2016 Roméo Nahon
** Last update	Wed Dec	7 14:08:10 2016 Roméo Nahon
*/

#include <include/my.h>

void	init()
{
  initscr();
  nocbreak();
  noecho();
  raw();
}
int	count_x(char *buffer)
{
  int	x;
  int	i;

  i = - 1;
  x = 0;
  while (buffer[++i] != '\0')
    if (buffer[i] == 'X')
      x += 1;
  return (x);
}
int	set_coord(t_vector *coord, t_temp *temp, char *buffer)
{
  find_player(buffer, coord);
  find_enemy(buffer, coord);
  temp->x = coord->x;
  temp->y = coord->y;
  coord->score = 0;
  coord->defense = 0;
  coord->nb_x = count_x(buffer);
  coord->buffer = buffer;
}
int 	first_map(t_vector *coord, t_temp *temp, t_menu *menu)
{
  int 		fd;
  int			ch;
  char 		buffer[10000];

  coord->r = 1;
  fd = open("./map2.wf", O_RDONLY);
  if (fd == -1)
    return (84);
  read(fd, buffer, 10000);
  coord->buffer = buffer;
  find_arobase(buffer, coord);
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
int	main(int ac, char **av)
{
  t_vector	*coord;
  t_temp	*temp;
  char		buffer[10000];

  coord = malloc(sizeof(t_vector));
  temp = malloc(sizeof(t_temp));
  find_o(buffer, coord);
  set_coord(coord, temp, buffer);
  coord->c1 = 0;
  coord->c2 = 0;
  init();
  curs_set(0);
  happy_meal(coord, temp);
  endwin(); 	
  return (0);
}
