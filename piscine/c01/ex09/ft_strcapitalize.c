/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:33:09 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/07 15:24:51 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_num(char c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

int	ft_str_is_lower(char c)
{
	if (c < 97 || c > 122)
		return (0);
	return (1);
}

int	ft_str_is_upper(char c)
{
	if (c < 65 || c > 90)
		return (0);
	return (1);
}

int	ft_str_is_not_alphanum(char c)
{
	if (ft_str_is_upper(c) || ft_str_is_lower(c) || ft_str_is_num(c))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 || ft_str_is_not_alphanum(str[i - 1]))
		{
			if (ft_str_is_lower(str[i]))
				str[i] -= 32;
		}
		else if (ft_str_is_upper(str[i]))
			str[i] += 32;
		i++;
	}
	return (str);
}
