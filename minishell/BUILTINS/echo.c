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

t_bool	bt_echo(t_data *data)
{
	int		i;
	t_bool	new_line;

	if (str_cmp(data->cmd->args[1], "-n") == 0)
		new_line = FALSE;
	else
		new_line = TRUE;
	i = 2 - new_line;
	while (data->cmd->args[i])
	{
		put_str(data->cmd->args[i], STDOUT_FILENO);
		if (data->cmd->args[i + 1] != NULL)
			put_str(" ", STDOUT_FILENO);
		i++;
	}
	if (new_line == TRUE)
		put_str("\n", STDOUT_FILENO);
	return (TRUE);
}
