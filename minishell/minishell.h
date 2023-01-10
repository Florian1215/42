/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:02:00 by fguirama          #+#    #+#             */
/*   Updated: 2023/01/07 11:02:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// INCLUDE ----------------------------------------------------------
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// TYPEDEF ----------------------------------------------------------
typedef struct s_cmd	t_cmd;
typedef struct s_data	t_data;
typedef enum e_bool		t_bool;
typedef enum e_builtins	t_builtins;

// UTILS ------------------------------------------------------------
enum e_bool
{
	FALSE,
	TRUE,
};

char	**split(char const *s, int sep);
void	free_split(char **split, int i);
int		str_cmp(char *s1, char *s2);
int		str_n_cmp(const char *s1, const char *s2, int n);
char	*join_path(char const *s1, char const *s2);
void	put_char(char c, int fd);
void	put_str_nl(char *str, int fd);

// BUILTINS ---------------------------------------------------------
enum e_builtins
{
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
	NONE,
};

// EXEC -------------------------------------------------------------
struct s_cmd
{
	char		*cmd_path;
	char		**args;
	t_builtins	built_in;
	t_cmd		*next;
	t_data		*data;
};

struct s_data
{
	int		fd_in;
	int		fd_out;
	int		*pids;
	int		**pipes;
	int		n_pipes;
	char	**envp;
};

void	init_forks(t_data *data, t_cmd *commands);
void	execute(t_cmd *cmd, int i);
void	free_pipes(int **pipes, int n);

// PARSING ----------------------------------------------------------
t_cmd	*parsing(char *line, char **paths);

#endif
