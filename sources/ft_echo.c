#include "../minishell.h"

int				ft_echo(char **args)
{
	char	flag;
	int		i;

	flag = 0;
	i = 0;
	args++;
	if (*args && (*args)[i++] == '-')
	{
		while ((*args)[i] == 'n')
			i++;
		if (!(*args)[i])
		{
			flag = 'n';
			args++;
		}
	}
	while (*args)
	{
		ft_putstr(*args++);
		if (*args)
			ft_putchar(' ');
	}
	if (!flag)
		ft_nl();
	return (1);
}
