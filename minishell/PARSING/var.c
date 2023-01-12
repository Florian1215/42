/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:36:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/12 09:36:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_bool	get_var(t_data *data, char *line)
{
	char	**res;
	char	*key;
	char	*value;
	int		i;

	res = split(line, ' ');
	if (!res)
		return (FALSE);
	i = find_char(res[0], '=');
	if (i == -1 || !i || i == str_len(res[0]) || size_tab(res) != 1)
		return (free_split(res, -1), FALSE);
	split_once(res[0], &key, &value, '=');
	add_item(&data->var, key, value);
	printf("add var\n");
	return (free_split(res, -1), TRUE);
}

static char	*get_key(char *s)
{
	char	*res;
	int		len;
	int		i;

	len = 0;
	while (s[len] && s[len] != ' ')
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = s[i];
	return (res[i] = '\0', res);
}

static char	*replace(char *s1, int len_key, char *s2, int start)
{
	char	*res;
	int		size;
	int		i;
	int		j;

	size = (str_len(s1) - len_key - 1 + str_len(s2));
	printf("malloc size %d\n", size);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < size)
	{
		if (i < start)
			res[i] = s1[i];
		else if (i < len_key + start)
	}
	res[i] = '\0';
	return (free(key), free(s1), res);
}

char	**replace_var(t_data *data, char **split)
{
	char	*key;
	int		start;
	int		k;

	if (!split)
		return (NULL);
	k = 0;
	while (split[k])
	{
		start = find_char(split[k], '$');
		if (start == -1)
		{
			k++;
			continue ;
		}
		key = get_key(split[k] + start + 1);
		if (!key)
			return (free_split(split, -1), NULL);
		split[k] = replace(split[k], str_len(key), get_value(data->var, key), start);
		if (!split[k])
			return (free_split(split, -1), NULL);
	}
	return (split);
}
