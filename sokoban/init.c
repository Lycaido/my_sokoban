/*
** init.c for my_sokoban in /home/Rev/Delivery/PSU_2016_my_sokoban/bonus
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Dec	19 19:04:49 2016 Roméo Nahon
** Last update	Mon Dec	19 19:04:49 2016 Roméo Nahon
*/

#include "include/my.h"

int	set_coord_x(t_vector *coord, int valuey, int valuex)
{
	if (coord->c2 == 0)
	{
		coord->x_ = coord->x_o;
		coord->c2 = 1;
	}
	if (COORD(M, valuey, valuex) == 'O')
		coord->x_ = valuex;
}

int	set_coord_y(t_vector *coord, int valuey, int valuex)
{
	if (coord->c1 == 0)
	{
		coord->y_ = coord->y_o;
		coord->c1 = 1;
	}
	if (COORD(M, valuey, valuex) == 'O')
		coord->y_ = valuey;
}