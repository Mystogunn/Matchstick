/*
** algo2.c for algo2.c in /home/josselin/EPITECH/machtstick/CPE_2016_matchstick
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Wed Feb 22 01:10:31 2017 Josselin
** Last update Wed Feb 22 08:02:18 2017 Josselin
*/

#include <stdlib.h>
#include "my.h"

void	message_pos(char *line, char *remove)
{
  my_putstr("Player removed ");
  my_putstr(remove);
  my_putstr(" match(es) from line ");
  my_putstr(line);
  my_putstr("\n");
}

int	*create_map_space(int line)
{
  int	*i;
  int	a;
  int	j;

  a = 0;
  if ((i = malloc(sizeof(int) * (line + 1))) == NULL)
    return (0);
  j = line - 1;
  while (line > 0)
    {
      i[a] = j;
      j = j - 1;
      line = line - 1;
      a = a + 1;
    }
  return (i);
}

int	print_last_space(int tab, int line, int i, int remove)
{
  if (line == tab)
    i = i + remove;
  print_space(i);
  return (i);
}

void	print_line_star(int i)
{
  int	a;

  a = (i * 2) + 1;
  while (a-- > 0)
    my_putstr("*");
  my_putstr("\n");
}
