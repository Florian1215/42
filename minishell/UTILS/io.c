/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:50:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/11 09:50:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	put_str(char *s, int fd)
{
	write(fd, s, str_len(s));
}

void	put_str_nl(char *str, int fd)
{
	put_str(str, fd);
	write(fd, "\n", 1);
}
