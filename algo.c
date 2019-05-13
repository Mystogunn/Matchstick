/*
** algo.c for algo.c in /home/josselin/EPITECH/machtstick/CPE_2016_matchstick
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Mon Feb 20 19:41:00 2017 Josselin
** Last update Sun Feb 26 21:15:01 2017 Josselin
*/

#include <stdlib.h>
#include "my.h"

int	*create_map(int i)
{
  int	*stick;
  int	a;
  int	j;

  if ((stick = malloc(sizeof(int) * (i + 1))) == NULL)
    return (0);
  a = 0;
  j = 1;
  while (i > 0)
    {
      stick[a] = j;
      j = j + 2;
      a = a + 1;
      i = i - 1;
    }
  return (stick);
}

void	print_space(int i)
{
  while (i > 0)
    {
      my_putstr(" ");
      i = i - 1;
    }
}

void	print_stick(int stick)
{
  while (stick > 0)
    {
      my_putstr("|");
      stick = stick - 1;
    }
}

void	print_map(t_vars *vars, int line, int i, int remove)
{
  int	j;
  int	tab;
  int	c;

  tab = 0;
  c = 0;
  j = line;
  print_line_star(line);
  while (j > 0)
    {
      my_putstr("*");
      print_space((line - 1) - tab);
      print_stick(vars->stick[tab]);
      vars->a[c] = print_last_space(tab, i, vars->a[c], remove);
      my_putstr("*\n");
      tab = tab + 1;
      j = j - 1;
      c = c + 1;
    }
  print_line_star(line);
}

int		algo(int i, char *str)
{
  t_vars	vars;
  int		max_remove;

  max_remove = my_getnbr(str);
  vars.a = create_map_space(i);
  vars.stick = create_map(i);
  print_map(&vars, i, 0, 0);
  while (1)
    {
      my_putstr("\nYour turn:\nLine: ");
      if ((vars.line = get_next_line(0)) == NULL)
	return (0);
      while (check_input_line(i, &vars)  == -1)
	if ((vars.line = get_next_line(0)) == NULL)
	  return (0);
      if (player(&vars, i, max_remove) == -1)
	return (0);
      if (check_game(&vars, i) == -1)
	return (2);
      ia(&vars, i, max_remove);
      if (check_game(&vars, i) == -1)
	return (1);
    }
  return (0);
}
