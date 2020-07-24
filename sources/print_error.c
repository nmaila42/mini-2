#include "../minishell.h"

static void	mini_terminate(void)
{
	ft_putendl(": a fatal error occured: shell terminated.");
	if (g_env && *g_env)
		ft_strstrdel(&g_env);
	exit(EXIT_FAILURE);
}

void		mini_arr_error(char *err, char ***arrdel, int f)
{
	ft_putendl(err);
	if (arrdel && *arrdel)
	{
		ft_strstrdel(arrdel);
		**arrdel = NULL;
	}
	if (f)
		mini_terminate();
}

void		mini_error(char *err, int f)
{
	ft_putendl(err);
	if (f)
		mini_terminate();
}

//print the array or the environment varriables
int	print_env(char **ep)
{
	int	i;

	i = 0;
	while (ep[i])
		ft_putendl(ep[i++]);
	return (1);
}
