/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:14:22 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/21 12:02:37 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_dict	*ft_dict_error(t_dict *d)
{
	ft_dict_clear(d);
	ft_error(1);
	return (0);
}

int	ft_check_line(char *str, char **key, char **value)
{
	int		i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (!i || i > 12)
		return (0);
	*key = ft_strdup(str, i);
	str += i;
	while (ft_isspace(*str))
		str++;
	if (*str++ != ':')
		return (0);
	while (ft_isspace(*str))
		str++;
	i = 0;
	while (ft_isprint(str[i]))
		i++;
	*value = ft_strdup(str, i);
	return (i && str[i] == '\n');
}

t_dict	*ft_dict_check(t_dict *d)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (!ft_in_dict(d, ft_itoa(i)) || !ft_in_dict(d, ft_itoa(10 + i))
			|| !ft_in_dict(d, ft_itoa(10 * i)))
			return (ft_dict_error(d));
		i++;
	}
	if (!ft_in_dict(d, "100") || !ft_in_dict(d, "1000")
		|| !ft_in_dict(d, "1000000") || !ft_in_dict(d, "1000000000"))
		return (ft_dict_error(d));
	return (d);
}

t_dict	*ft_dict_create(char *content)
{
	t_dict	*new;
	t_dict	*prev;
	char	*key;
	char	*value;

	prev = NULL;
	while (*content)
	{
		if (*content == '\n')
			content++;
		if (!*content)
			break ;
		if (ft_check_line(content, &key, &value) && !ft_find_elem(prev, key))
		{
			new = ft_dict_create_elem(&key, &value, prev);
			if (!new)
				return (ft_dict_error(new));
			prev = new;
			while (*content != '\n')
				content++;
		}
		else
			return (ft_dict_error(new));
	}
	return (ft_dict_check(new));
}
