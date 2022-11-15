# include "get_next_line.h"

t_list	*ft_lstnew(char *buff)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->buff = buff;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst || !lst->next)
		return (lst);
	return (ft_lstlast(lst->next));
}

void	ft_lstadd_back(t_list **lst, t_list *new)
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

void	ft_list_remove_if(t_list **begin_list, void
*data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*l;
	t_list	*prev;
	t_list	*next;

	l = *begin_list;
	prev = NULL;
	while (l)
	{
		next = l->next;
		if (!(*cmp)(l->buff, data_ref))
		{
			if (prev)
				prev->next = l->next;
			else
				*begin_list = next;
			(*free_fct)(l->buff);
			free(l);
		}
		else
			prev = l;
		l = next;
	}
}