#include "../minishell.h"

size_t		ft_strarrlen(char **arr)
{
	size_t i;

	i = 0;
	if (arr)
		while (arr[i])
			i++;
	return (i);
}

void	ft_strstrdel(char ***del_me)
{
	int i;

	i = 0;
	while ((*del_me)[i])
		free((*del_me)[i++]);
	free(*del_me);
}

char	**ft_strarrrealloc(char **arr, char *str)
{
	char	**new;
	size_t	length;
	int		i;

	i = 0;
	length = ft_strarrlen(arr);
	new = (char**)malloc(sizeof(char*) * (length + 2));
	new[length + 1] = NULL;
	while (length--)
	{
		new[i] = ft_strdup(arr[i]);
		i++;
	}
	new[i] = ft_strdup(str);
	ft_strstrdel(&arr);
	return (new);
}

char	**ft_strarrdup(char **arr)
{
	char	**dup;
	char	**dup_z;
	size_t	len;

	if (!(len = ft_strarrlen(arr)))
		return (NULL);
	if (!(dup = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	dup_z = dup;
	dup[len] = NULL;
	while (len--)
		*dup++ = ft_strdup(*arr++);
	return (dup_z);
}