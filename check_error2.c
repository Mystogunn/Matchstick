/*
** check_error2.c for matchstik in /home/josselin/EPITECH/machtstick/CPE_2016_matchstick
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Sun Feb 26 05:21:21 2017 Josselin
** Last update Sun Feb 26 07:56:18 2017 Josselin
*/

#include <stdlib.h>
#include "my.h"

int	check_match2(t_vars *vars, int max_remove)
{
  int	i;
  int	a;

  i = my_getnbr(vars->remove);
  if (max_remove < i)
    {
      my_putstr("Error: you cannot remove more than ");
      my_put_nbr(max_remove);
      my_putstr(" matches per turn\n");
      return (-1);
    }
  a = my_getnbr(vars->line);
  if (i > vars->stick[(a - 1)])
    {
      my_putstr("Error: not enough matches on this line\n");
      return (-1);
    }
  return (0);
}

int	check_match(t_vars *vars)
{
  if (vars->remove == NULL)
    {
      my_putstr("\nError: invalid input (positive number expected)\n");
      return (-1);
    }
  if (vars->remove[0] == 0)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (-1);
    }
  return (0);
}

int	check_input_remove(t_vars *vars, int max_remove)
{
  int	a;

  if (check_match(vars) == -1)
    return (-1);
  a = my_getnbr(vars->remove);
  if (a == 0)
    {
      my_putstr("Error: you have to remove at least one match\n");
      return (-1);
    }
  a = 0;
  while (vars->remove[a] != 0)
    {
      if  (vars->remove[a] < '0' || vars->remove[a] > '9')
	{
	  my_putstr("Error: invalid input (positive number expected)\n");
	  return (-1);
	}
      a = a + 1;
    }
  if (check_match2(vars, max_remove) == -1)
    return (-1);
  return (0);
}
