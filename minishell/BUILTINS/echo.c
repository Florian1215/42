/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:28:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/10 15:28:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_bool	bt_echo(char **args)
{
	int		i;
	t_bool	new_line;

	if (str_cmp(args[1], "-n") == 0)
		new_line = FALSE;
	else
		new_line = TRUE;
	i = 2;
	while (args[i])
	{
		put_str(args[i], STDOUT_FILENO);
		if (args[i + 1] != NULL)
			put_str(" ", STDOUT_FILENO);
		i++;
	}
	if (new_line == TRUE)
		put_str("\n", STDOUT_FILENO);
	return (TRUE);
}
