/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:51:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/11 10:51:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_env(t_dict *env)
{
	t_dict	*tmp;
	char	**res;
	int		size;
	int		i;

	size = 0;
	tmp = env;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	res = malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i++] = join_char(env->key, env->value, '=');
		env = env->next;
	}
	return (res[i] = NULL, res);
}

t_dict	*init_env(char **envp)
{
	t_dict	*env;
	int		i;
	char	*key;
	char	*value;

	env = NULL;
	key = NULL;
	value = NULL;
	i = -1;
	while (envp[++i])
	{
		if (!split_once(envp[i], &key, &value, '='))
			return (NULL); //FREE ALL
		add_item(&env, key, value);
	}
	return (env);
}
