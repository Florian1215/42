/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:33:28 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/11 08:33:31 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	error(char *s1, char *s2, char *s3, char *s4)
{
	char	*strings[4];
	int		i;

	strings[0] = s1;
	strings[1] = s2;
	strings[2] = s3;
	strings[3] = s4;
	i = 0;
	while (i < 4)
	{
		put_str(strings[i], STDERR_FILENO);
		if (i != 3)
			put_str(": ", STDERR_FILENO);
		i++;
	}
	put_str("\n", STDERR_FILENO);
}

t_bool	bt_cd(t_data *data)
{
	char	*cur_wd;
	// tu dois update env (pour ca fait juste add_item avec PWD en key, et le nouveau path en value)
	// tu ne gere pas juste le cd, penses y
	// et aussi ta gestion d'erreur est assez catastrophique on en reparle quand tu liras ca :) (je parle du error et du cur_wd)

	cur_wd = NULL;
	cur_wd = getcwd(cur_wd, 42);
	if (chdir(data->cmd->args[1]) != 0)
	{
		error("minishell", \
		data->cmd->args[0], \
		data->cmd->args[1], \
		strerror(errno));
		return (0);
	}
	else if (data->n_pipes != 0)
		chdir(cur_wd);
	return (1);
}

// exemple de belle fonction

//t_bool	bt_cd(t_data *data)
//{
//	if (data->n_pipes)
//	{
//		if (chdir(data->cmd->args[1]) != 0)
//		{
//			error("minishell", data->cmd->args[0], \
//			data->cmd->args[1], strerror(errno));
//			return (0);
//		}
//	}
//	return (1);
//}
