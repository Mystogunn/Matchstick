/*
** my.h for macthstick in /home/josselin/EPITECH/machtstick/CPE_2016_matchstick/include
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Mon Feb 20 23:43:46 2017 Josselin
** Last update Sun Feb 26 16:31:43 2017 Josselin
*/

#ifndef		MY_H_
# define	MY_H_
//#define malloc(x) NULL

typedef struct	s_vars
{
  char	*line;
  char	*remove;
  int	*a;
  int	*stick;
}		t_vars;

int     my_put_nbr(int nb);
void	my_putstr(char *str);
int     my_getnbr(char *str);
int     my_strlen(char *str);
void    print_tab(char **str);
char    *get_next_line(const int fd);
int     my_put_nbr(int nb);
int     algo(int i, char *str);
void    print_line_star(int i);
void    print_space(int i);
int	print_last_space(int tab, int line, int i, int remove);
int     *create_map_space(int line);
void    message_pos(char *line, char *remove);
int     my_strcmp(char *s1, char *s2);
int     check_error(char **av);
int	player(t_vars *vars, int i, int max_remove);
void    print_map(t_vars *vars, int line, int i, int remove);
int    ia(t_vars *vars, int i,int max_remove);
int     check_game(t_vars *vars, int i);
int     check_input_line(int i, t_vars *vars);
int     check_input_remove(t_vars *vars, int max_remove);

#endif /* !MY_H_ */
