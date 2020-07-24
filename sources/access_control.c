#include "../minishell.h"

//permission to acces the files and dereference symbolik link
//F_OK --. existence of a file
//X_OK -- file exists and grants read, write, and execute permissions

int		access_control(char *str)
{
	if (access(str, F_OK) != 0)
	{
		ft_putstr(str);
		ft_putendl(": Command not found.");
		return (0);
	}
	else if (access(str, X_OK) != 0)
	{
		ft_putstr(str);
		ft_putendl(": Permission denied");
		return (0);
	}
	return (1);
}

int		access_control_f(char *str)
{
	if (access(str, F_OK) != 0)
	{
		ft_putstr(str);
		ft_putendl(": File or directory does not exist.");
		return (0);
	}
	else if (access(str, X_OK) != 0)
	{
		ft_putstr(str);
		ft_putendl(": Permission denied");
		return (0);
	}
	return (1);
}
