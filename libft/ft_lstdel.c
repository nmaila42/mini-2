#include "libft.h"

void	ft_lstdel(t_list **alsti, void (*del)(void *, size_t))
{
	t_list *temp;

	temp = NULL;
	if (alsti)
	{
		temp = *alsti;
		while (*alsti)
		{
			del((*alsti)->content, (*alsti)->content_size);
			free(*alsti);
			*alsti = (*alsti)->next;
		}
	}
	temp = NULL;
}
