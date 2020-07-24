#ifndef MINISHELL_H
# define MINISHELL_H

#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

# ifndef ARG_MAX
#  define ARG_MAX (256 * 1024)
# endif

char            *ft_readline();
int             ft_launch(char **args);
int             ft_execute(char **args);
char	        **ft_split(char *str);


//to bo contined in time
//void            echo_out(char **str, int pos);
//void            qoute_checker(char **input, char *f);
//void            ft_cd(char **args);
//void            exit_shell(void);
//int			  echo_builtin(char **args);
#endif