#ifndef MINISHELL_H
#define MINISHELL_H


# include "libft/libft.h"
# include <dirent.h>
# include <limits.h>
# include <sys/wait.h>

# define SEARCH_OFF	0
# define SEARCH_ON	01
# define SEARCH_VAL	02

// errono accompanied by error message bellow
# define NONFATAL_ME 0
# define FATAL_ME	1

// display this message before terminating with error value above
# define ME_CLSERR	"error closing directory stream"
# define ME_MEMERR	"error allocating memory"

// evirronment varriavle array of sizze arg_max
# ifndef ARG_MAX
#  define ARG_MAX (256 * 1024)
# endif

// storts environment Variables, keys = value
char		**g_env;

char		*param_search(char **env, char *env_var, char *arg, int flag);
char		**ft_strarrdup(char **arr);
size_t		ft_strarrlen(char **arr);
void		ft_strstrdel(char ***del_me);
char		**ft_strarrrealloc(char **arr, char *str);
void		ft_setenv(char *var, char *value, size_t varlen, size_t vallen);
void		ft_unsetenv(char *v_name);
int			ft_cd(char *path);
char		**parser(char *input);
void		expand(char **args);

int			unsetenv_checker(char **args);
int			setenv_checker(char **args);
int			ft_echo(char **args);


void	    mini_arr_error(char *err, char ***arrdel, int f);
void	    mini_error(char *err, int f);
int			print_env(char **ep);

int			access_control(char *str);
int			access_control_f(char *str);

#endif