/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:01:17 by fguirama          #+#    #+#             */
/*   Updated: 2022/08/21 22:10:56 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

unsigned long long int	ft_atoi(char *str);
char					*ft_itoa(unsigned long long int nb);
void					ft_error(int dict);
int						ft_isdigit(char c);
int						ft_isprint(char c);
int						ft_isspace(char c);
void					ft_putchar(char c);
void					ft_putstr(char *str);
int						ft_strlen(char *str);
char					*ft_strdup(char *str, int size);
int						ft_check_nb(char *nb);

typedef struct data
{
	char		*key;
	char		*value;
	struct data	*next;
}	t_dict;

int						ft_check_args(int ac, char **av, char **path,
							char **nb);
void					ft_dict_clear(t_dict *d);
t_dict					*ft_dict_create_elem(char **key, char **value,
							t_dict *ptr);
t_dict					*ft_dict_create(char *content);
t_dict					*ft_find_elem(t_dict *begin_list, char *key);
int						ft_dict_cmp(char *key1, char *key2);
t_dict					*ft_in_dict(t_dict *d, char *key);
char					*ft_read_file(char *path);

void					ft_print(t_dict *d, char *value);

#endif
