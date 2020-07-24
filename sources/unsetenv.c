#include "../minishell.h"

void	ft_unsetenv(char *v_name)
{
	int		i;
	size_t	vlen;

	i = 0;
	vlen = ft_strlen(v_name);
	while (g_env[i])
	{
		if (!ft_strncmp(g_env[i], v_name, vlen) && g_env[i][vlen] == '=')
			break ;
		i++;
	}
	if (g_env[i])
	{
		free(g_env[i]);
		g_env[i] = NULL;
		while (g_env[++i])
			g_env[i - 1] = g_env[i];
		g_env[i - 1] = NULL;
	}
}

int		unsetenv_checker(char **args)
{
	if (args[1])
		ft_unsetenv(args[1]);
	else
		mini_error("No arguments.", 0);
	return (1);
}
