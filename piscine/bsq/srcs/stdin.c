/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:30:41 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/24 17:30:45 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_read	*ft_create_elem(char *str, t_read *ptr)
{
	t_read	*read;

	read = malloc(sizeof(t_read));
	if (!read)
		return (NULL);
	read->next = ptr;
	read->str = ft_strdup(str);
	return (read);
}

t_read	*ft_list_last(t_read *begin_list)
{
	if (!begin_list || !begin_list->next)
		return (begin_list);
	return (ft_list_last(begin_list->next));
}

t_read	*ft_reverse(t_read *ptr)
{
	t_read	*first;
	t_read	*prev;
	t_read	*next;

	first = ft_list_last(ptr);
	prev = NULL;
	while (ptr != first)
	{
		next = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = next;
	}
	ptr->next = prev;
	return (ptr);
}

char	*ft_convert_stdin(char *content, int len, t_read *r)
{
	int		j;
	int		i;
	t_read	*tmp;

	content = malloc(sizeof(char) * (len * 100));
	r = ft_reverse(r);
	i = 0;
	while (r)
	{
		j = 0;
		while (r->str[j])
		{
			content[i] = r->str[j];
			j++;
			i++;
		}
		i--;
		free(r->str);
		tmp = r->next;
		free(r);
		r = tmp;
	}
	content[++i] = '\0';
	return (content);
}

char	*ft_stdin(void)
{
	t_read	*r;
	char	buffer[100];
	char	*content;
	int		len;

	content = NULL;
	r = NULL;
	len = 1;
	while (read(0, &buffer, 100))
	{
		r = ft_create_elem(buffer, r);
		ft_clear_buffer(buffer);
		len++;
	}
	return (ft_convert_stdin(content, len, r));
}
