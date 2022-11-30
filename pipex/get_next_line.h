/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:24:42 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/15 10:24:42 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# if BUFFER_SIZE >= 10000000
#  define BUFFER_SIZE 20
# endif

#endif