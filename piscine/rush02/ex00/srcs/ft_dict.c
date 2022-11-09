/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:48:33 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/21 11:49:55 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_dict_cmp(char *key1, char *key2)
{
	int	i;

	i = 0;
	while (key1[i] == key2[i] && key1[i] != '\0')
		i++;
	return (key1[i] - key2[i]);
}

t_dict	*ft_find_elem(t_dict *begin_list, char *key)
{
	if (!begin_list || !ft_dict_cmp(begin_list->key, key))
		return (begin_list);
	return (ft_find_elem(begin_list->next, key));
}

t_dict	*ft_in_dict(t_dict *d, char *key)
{
	return (ft_find_elem(d, key));
}

void	ft_dict_clear(t_dict *d)
{
	free(d->key);
	free(d->value);
	free(d);
}

t_dict	*ft_dict_create_elem(char **key, char **value, t_dict *ptr)
{
	t_dict	*d;

	d = malloc(sizeof(t_dict));
	d->key = *key;
	d->value = *value;
	d->next = ptr;
	return (d);
}
