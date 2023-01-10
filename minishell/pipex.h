/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:00:09 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/02 16:09:40 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>

// ERROR
int		check_args(int ac, char **av);

//UTILS
void	ft_printf(const char *format, ...);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s);
char	**ft_free_split(char **split, int i);
char	*get_binary(char **args, int free_split);

#endif