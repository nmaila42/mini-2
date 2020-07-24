#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *temp;

	if (alst && new)
	{
		temp = *alst;
		*alst = new;
		new->next = temp;
	}
}