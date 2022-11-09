#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_ptr;

	if (!*lst)
		*lst = new;
	else
	{
		last_ptr = ft_lstlast(*lst);
		last_ptr->next = new;
	}
}