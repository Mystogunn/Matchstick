/*
** player.c for first_player.c in /home/josselin/EPITECH/machtstick/CPE_2016_matchstick
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Fri Feb 24 07:49:47 2017 Josselin
** Last update Sun Feb 26 09:25:34 2017 Josselin
*/

#include <stdlib.h>
#include "my.h"

int	player(t_vars *vars, int i, int max_remove)
{
  int	re;
  int	li;

  my_putstr("Matches: ");
  if ((vars->remove = get_next_line(0)) == NULL)
    return (-1);
  while (check_input_remove(vars, max_remove) == -1)
    {
      my_putstr("line: ");
      if ((vars->line = get_next_line(0)) == NULL)
	return (-1);
      while (check_input_line(i, vars)  == -1)
	if ((vars->line = get_next_line(0)) == NULL)
	  return (-1);
      my_putstr("Matches: ");
      if ((vars->remove = get_next_line(0)) == NULL)
	return (-1);
    }
  message_pos(vars->line, vars->remove);
  li = my_getnbr(vars->line);
  re = my_getnbr(vars->remove);
  vars->stick[li - 1] = vars->stick[li - 1] - re;
  print_map(vars, i, (li - 1), re);
  return (0);
}
