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
# include <stdlib.h>

typedef struct s_list	t_list;
typedef enum e_list		t_lst;

struct s_list
{
	char			*buff;
	struct s_list	*next;
};

char	*get_next_line(int fd);
t_list	*lstlast(t_list *lst);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

#endif