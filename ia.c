/*
** ia.c for ia.c in /home/josselin/EPITECH/machtstick/CPE_2016_matchstick
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Sat Feb 25 14:49:59 2017 Josselin
** Last update Sun Feb 26 18:35:17 2017 Josselin
*/

#include "my.h"

void	message_ia(int line, int remove)
{
  my_putstr("AI removed ");
  my_put_nbr(remove);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putstr("\n");
}

void	ia_end_game2(t_vars *vars, int i, int max_remove, int line_remove)
{
  int	re;

  re = vars->stick[line_remove] - 1;
  if (max_remove >= vars->stick[line_remove])
    {
      vars->stick[line_remove] = vars->stick[line_remove] - re;
      message_ia((line_remove + 1), re);
      print_map(vars, i, line_remove, re);
    }
  else
    {
      vars->stick[line_remove] = vars->stick[line_remove] - max_remove;
      message_ia((line_remove + 1), (vars->stick[line_remove] - max_remove));
      print_map(vars, i, line_remove, (vars->stick[line_remove] - max_remove));
    }
}

int	ia_end_game(t_vars *vars, int i, int max_remove)
{
  int	b;
  int	a;
  int	c;

  c = i;
  a = 0;
  b = 0;
  while ((i - 1) > 0)
    {
      if (vars->stick[a] != 0)
	b++;
      i--;
      a++;
    }
  if (b == 1)
    {
      a = 0;
      while (vars->stick[a] == 0)
	a++;
      if (vars->stick[a] == 1)
	return (0);
      ia_end_game2(vars, c, max_remove, a);
      return (-1);
    }
  return (0);
}

void	default_ia(t_vars *vars, int i,int max_remove)
{
  int	a;
  int	b;

  a = i - 1;
  while (vars->stick[a] == 0)
    a--;
  if (vars->stick[a] >= max_remove)
    {
      vars->stick[a] = vars->stick[a] - max_remove;
      message_ia((a + 1), max_remove);
      print_map(vars, i, a, max_remove);
    }
  else
    {
      b = vars->stick[a];
      vars->stick[a] = vars->stick[a] - vars->stick[a];
      message_ia((a + 1), b);
      print_map(vars, i, a, b);
    }
}

int	ia(t_vars *vars, int i,int max_remove)
{
  my_putstr("\nAI's turn...\n");
  if (ia_end_game(vars, i, max_remove) == -1)
    return (0);
  else
    default_ia(vars, i, max_remove);
  return (0);
}
