/*
** check_error.c for check_error.c in /home/josselin/EPITECH/machtstick/CPE_2016_matchstick
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Fri Feb 24 11:26:09 2017 Josselin
** Last update Sun Feb 26 07:33:54 2017 Josselin
*/

#include <stdlib.h>
#include "my.h"

int	check_error(char **av)
{
  int	i;
  int	a;

  i = 0;
  while (av[1][i] != 0)
    {
      if (av[1][i] < '0' || av[1][i] > '9')
	return (-1);
      i = i + 1;
    }
  i = 0;
  while (av[2][i] != 0)
    {
      if (av[2][i] < '0' || av[2][i] > '9')
	return (-1);
      i = i + 1;
    }
  i = my_getnbr(av[1]);
  a = my_getnbr(av[2]);
  if (i > 100 || i < 0 || a < 1 || av[1][0] == '0' || av[2][0] == '0')
    return (-1);
  return (0);
}

int	check_input(t_vars *vars)
{
  if (vars->line == NULL)
    {
      my_putstr("\nError: invalid input (positive number expected)\nLine: ");
      return (-1);
    }
  if (vars->line[0] == 0)
    {
      my_putstr("Error: invalid input (positive number expected)\nLine: ");
      return (-1);
    }
  return (0);
}

int	check_input_line2(t_vars *vars, int line)
{
  int	i;

  i = my_getnbr(vars->line);
  if (vars->stick[i - 1] == 0)
    {
      my_putstr("Error: this line is out of range\nLine: ");
      return (-1);
    }
  i = my_getnbr(vars->line);
  if (i > line)
    {
      my_putstr("Error: this line is out of range\nLine: ");
      return (-1);
    }
  return (0);
}

int	check_input_line(int i, t_vars *vars)
{
  int	a;

  if (check_input(vars) == -1)
    return (-1);
  a = my_getnbr(vars->line);
  if (a == 0)
    {
      my_putstr("Error: this line is out of range\nLine: ");
      return (-1);
    }
  a = 0;
  while (vars->line[a] != 0)
    {
      if (vars->line[a] < '0' || vars->line[a] > '9')
	{
	  my_putstr("Error: invalid input (positive number expected)\nLine: ");
	  return (-1);
	}
      a = a + 1;
    }
  if (check_input_line2(vars, i) == -1)
    return (-1);
  return (0);
}
