#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*content;

	while (lst)
	{
		content = (*f)(lst->content);
		(*del)(lst->content);
		lst = lst->next;
	}
}