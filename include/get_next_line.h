/*
** get_next_line.h for get_next_line.h in /home/josselin/EPITECH/Get_next/bootstrap/include
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Fri Jan  6 05:29:11 2017 Josselin
** Last update Fri Feb 24 00:24:08 2017 Josselin
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_

# ifndef		READ_SIZE
#  define		READ_SIZE (1)
# endif /* !READ_SIZE */ 
# define		SIZE_MALLOC (4096)

typedef struct	s_vars
{
  int	idx;
  int	idx_line;
  int	k;
  int	value_read;
  char	buf[READ_SIZE + 1];
  char	*line;
}	t_vars;

char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
