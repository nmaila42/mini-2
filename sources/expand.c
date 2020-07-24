#include "../minishell.h"

//command expansion
//command expansion. What I mean by this is that I can nest commands in other commands.
//eg >echo abc $echo cde $echo failed


//injects the the new argument input "ptr" into "str"  and makes it the next command
static void	injector(char *value, char **str, char *ptr)
{
	char new[ARG_MAX];
	char *check;

	ft_bzero(new, ARG_MAX);
	ft_memcpy(new, *str, ptr - *str); // from parnt string, inject cmds after the 1st one int new
	if (value)
		ft_strcat(new, value); //if the previous excution succeded join result to the new new[]
	else
	{
		if (!ptr[1])
			ft_strcat(new, "$"); //if there are no more cmds add $
	}
	if ((check = ft_strchr(ptr, ' ')))
		ft_strcat(new, check);
	ft_strdel(str);
	*str = ft_strdup(new);
	ft_strdel(&value);
}

//checks if there is an expanded cammond input eg $echo $echo
static void	expand_checker(char **str)
{
	int		j;
	char	*ptr;
	char	*temp;
	char	*value;
	char	*word;

	j = 0;
	ptr = NULL;
	while ((*str)[j])
	{
		if ((ptr = ft_strchr(&(*str)[j], '$')) && (*str)[0])
		{
			if (!(word = ft_strchr(ptr, ' '))) //checks if there are no spaces in the ptr after $, if spaces are not found
				word = ft_strchr(ptr, '\0'); //null terminates the str and ends, mean the following input($echo) is the last one
			j = (ptr - *str) + 1;  //moves j to the second input of the str arg
			temp = ft_strsub(ptr, 1, word - (ptr + 1)); //strips all other input args after the 1st one
			value = param_search(g_env, temp, NULL, SEARCH_VAL); //executes the cmd of the expanded comand that was  stripped above
			injector(value, str, ptr); // injects the remaining cmd ar into str and loop until str == Nullt
			ft_strdel(&temp); //clear temp
		}
		else
			j++;
	}
}

void		expand(char **args)
{
	if (!args || !*args || !**args)
		return ;
	if (args[1])
		args++;
	else
		return ;
	while (*args)
	{
		expand_checker(args);
		args++;
	}
}
