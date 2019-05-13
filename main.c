/*
** main.c for main.c in /home/josselin/EPITECH/machtstick/CPE_2016_matchstick
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Mon Feb 20 18:45:21 2017 Josselin
** Last update Sun Feb 26 09:02:43 2017 Josselin
*/

#include "my.h"

int	main(int ac, char **av)
{
  int	i;

  if (ac != 3)
    return (84);
  i = my_getnbr(av[1]);
  if ((check_error(av)) == -1)
    return (84);
  i = algo(i, av[2]);
  if (i == 2)
    my_putstr("You lost, too bad...\n");
  if (i == 1)
    my_putstr("I lost... snif... but I’ll get you next time!!\n");
  return (i);
}
