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
# include <limits.h>
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

t_bool	split_once(char *str, char **s1, char **s2, int sep);
char	**split(char const *s, int sep);
int		str_cmp(char *s1, char *s2);
int		str_len(const char *s);
int		find_char(char *s, int c);
void	put_str(char *s, int fd);
void	put_str_nl(char *str, int fd);
char	*join_char(char *s1, char *s2, int c);
int		size_tab(char **tab);
int		atoi_(char *nb, unsigned char *var);

// DICT -------------------------------------------------------------
struct s_dict
{
	char	*key;
	char	*value;
	t_dict	*next;
};

t_dict	*init_env(char **envp);
char	**get_env(t_dict *env);
t_bool	add_item(t_dict **dict, char *key, char *value);
t_bool	check_key(t_dict *dict, char *key);
char	*get_value(t_dict *dict, char *key);

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

t_bool	bt_pwd(t_data *data);
t_bool	bt_echo(t_data *data);
t_bool	bt_cd(t_data *data);

// EXEC -------------------------------------------------------------
struct s_cmd
{
	char		*cmd_path;
	char		**args;
	t_builtins	built_in;
	t_cmd		*next;
};

enum e_io
{
	IN,
	OUT,
};

struct s_data
{
	t_cmd	*cmd;
	t_dict	*env;
	t_dict	*var;
	int		fd[2];
	int		std[2];
	int		*pids;
	int		**pipes;
	int		n_pipes;
};

void	init_forks(t_data *data);
void	init_pids(t_data *data);
void	init_pipes(t_data *data);
void	execute(t_data *data, int i);
void	execute_bt(t_data *data);

// PARSING ----------------------------------------------------------
t_bool	parsing(t_data *data, char *line);
t_bool	add_back(t_data *data, char *line, char **paths);
t_bool	get_var(t_data *data, char *line);
char	**replace_var(t_data *data, char **split);

// FREE -------------------------------------------------------------
void	free_split(char **split, int i);
void	free_pipes(int **pipes, int n);
void	free_dict(t_dict **dict);
void	free_cmds(t_cmd **cmd);

#endif
