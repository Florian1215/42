/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:53:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/11 10:53:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_dict	*last_item(t_dict *dict)
{
	if (!dict || !dict->next)
		return (dict);
	return (last_item(dict->next));
}

t_bool	add_item(t_dict **dict, char *key, char *value)
{
	t_dict	*new;

	new = malloc(sizeof(t_dict));
	if (!new)
		return (ERROR);
	new->key = key;
	new->value = value;
	new->next = NULL;
	if (!*dict)
		*dict = new;
	else
		last_item(*dict)->next = new;
	return (SUCCESS);
}

char	*get_value(t_dict *dict, char *key)
{
	while (dict && dict->next)
	{
		if (!str_cmp(dict->key, key))
			return (dict->value);
		dict = dict->next;
	}
	return (NULL);
}

t_bool	check_key(t_dict *dict, char *key)
{
	while (dict && dict->next)
	{
		if (!str_cmp(dict->key, key))
			return (TRUE);
		dict = dict->next;
	}
	return (FALSE);
}
