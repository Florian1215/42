/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:41:45 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/24 17:41:47 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
	int		line;
	int		col;
	char	empty;
	char	fill;
	char	obs;
	char	**map;
}	t_map;

typedef struct s_read
{
	struct s_read	*next;
	char			*str;
}	t_read;

void	ft_error(void);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_clear_buffer(char *str);
void	ft_solve_map(char *content);
int		ft_isdigit(char c);
int		ft_isprintable(char c);
int		ft_atoi(char *str, int size);
int		ft_strlen(char *str, char end);
int		ft_check_line(char *str);
int		ft_check_data(char *content);
int		ft_check_only_char(char *content);
char	*ft_stdin(void);
char	*ft_strdup(char *src);
char	*ft_read_file(char *path);
t_map	ft_pars_map(char *content);

#endif