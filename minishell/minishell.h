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
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <unistd.h>

// TYPEDEF ----------------------------------------------------------
typedef struct s_cmd	t_cmd;
typedef struct s_dict	t_dict;
typedef struct s_data	t_data;
typedef enum e_bool		t_bool;
typedef enum e_builtins	t_builtins;

// UTILS ------------------------------------------------------------
enum e_bool
{
	FALSE,
	TRUE,
	ERROR = 0,
	SUCCESS = 1,
};

char	**split(char const *s, int sep);
void	free_split(char **split, int i);
int		str_cmp(char *s1, char *s2);
int		str_n_cmp(const char *s1, const char *s2, int n);
int		str_len(const char *s);
int		find_char(char *s, int c);
void	put_str(char *s, int fd);
void	put_str_nl(char *str, int fd);
char	*join_char(char *s1, char *s2, int c);
int		size_tab(char **tab);

// DICT -------------------------------------------------------------
struct s_dict
{
	char	*key;
	char	*value;
	t_dict	*next;
};

t_bool	split_once(char *str, char **s1, char **s2, int sep);
t_dict	*init_env(char **envp);
t_bool	add_item(t_dict **dict, char *key, char *value);
char	*get_value(t_dict *dict, char *key);
t_bool	check_key(t_dict *dict, char *key);
char	**get_env(t_dict *env);
void	free_dict(t_dict **dict);

// BUILTINS ---------------------------------------------------------
enum e_builtins
{
	ENV,
	EXPORT,
	CD,
	UNSET,
	EXIT,
	PWD,
	ECHO,
	NONE,
};

t_bool	bt_pwd(char **args);
t_bool	bt_echo(char **args);
t_bool	bt_cd(char **args);

// EXEC -------------------------------------------------------------
struct s_cmd
{
	char		*cmd_path;
	char		**args;
	t_builtins	built_in;
	t_cmd		*next;
};

struct s_data
{
	t_cmd	*cmd;
	t_dict	*env;
	t_dict	*var;
	int		fd_in;
	int		fd_out;
	int		std_in;
	int		std_out;
	int		*pids;
	int		**pipes;
	int		n_pipes;
};

void	init_forks(t_data *data);
void	init_pids(t_data *data);
void	init_pipes(t_data *data);
void	execute(t_data *data, int i);
void	free_pipes(int **pipes, int n);
void	execute_bt(t_cmd *cmd);

// PARSING ----------------------------------------------------------
t_bool	parsing(t_data *data, char *line);
t_bool	add_back(t_cmd **cmd, char *line, char **paths);
void	free_cmds(t_cmd **cmd);

#endif
