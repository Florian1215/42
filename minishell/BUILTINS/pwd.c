/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:11:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/10 16:11:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_bool	bt_pwd(t_data *data)
{
	char	*path;

	(void)data;
	path = NULL;
	path = getcwd(path, 42);
	printf("%s\n", path);
	free(path);
	return (TRUE);
}
