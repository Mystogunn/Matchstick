/*
** check_game.c for check_game.c in /home/josselin/EPITECH/machtstick/CPE_2016_matchstick
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Sat Feb 25 17:26:57 2017 Josselin
** Last update Sun Feb 26 04:48:43 2017 Josselin
*/

#include "my.h"

int	check_game(t_vars *vars, int i)
{
  while (i > 0)
    {
      if (vars->stick[i - 1] != 0)
	return (0);
      i = i - 1;
    }
  return (-1);
}
