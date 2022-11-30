/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:00:09 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/30 15:07:47 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>

// GNL
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*buff;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
void	ft_lstrm_first(t_list **lst);
t_list	*ft_lstnew(char *buff);
void	ft_lstadd_back(t_list **lst, t_list *new_lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_find_nl(t_list *lst, int one_lst);

# define BUFFER_SIZE 20



# include <stdio.h>

#endif