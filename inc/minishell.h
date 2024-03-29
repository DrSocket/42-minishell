/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 20:20:07 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/16 18:14:18 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/get_next_line.h"
# include "../lib/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <errno.h>

# define SUCCESS			0
# define ERROR_MALLOC		1

# define REDIRECT			1
# define PIPE				2
# define STDOUT				3
# define ARG				4

# define EXIT				1
# define ECHO				2
# define CD					3
# define PWD				4
# define EXPORT 			5
# define UNSET				6
# define ENV				7
# define NOTFOUND			8
# define EXEC				9

typedef struct		s_hist
{
	char			*line;
	struct s_hist	*next;
}					t_hist;

typedef struct		s_cmd
{
	int				cmd;
	int				output;
	t_list			*fd_out;
	int				input;
	int				fd_in;
	char			*arg;
	char			*result;
	struct s_cmd	*next;
	int				nb_cmd;
	char			*cmd_temp;
	int				exept_case;
	char			*cmd_n_found;
}					t_cmd;

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_data
{
	t_hist			*historic;
	t_cmd			*lst_cmd;
	t_env			*lst_env;
	t_env			*lst_env_waiting;

	int				exit;
	char			path[1000];
	char			*pipe;
	int				ret;
	int				step_cmd;

	int				i;
	int				size;
	char			**cmd;
	int				fd;
	int				empty_pipe;
	int				exit_status;
}					t_data;

extern	t_data		*g_data;

int					ft_start(t_data *data);
void				ft_exit(t_cmd *cmd);
int					ft_init_data(t_data *data);
int					ft_init_env(t_env *env, char **environ);
int					ft_init_lst(t_cmd **lst_cmd);
void				ft_print_prompt();
void				ft_exec_line(t_data *data);
int					init_fork(char *line);
int					executor(t_cmd **cmd, int **tube);
void				close_tube(int **tube, t_cmd *cmd);
int					parser(t_cmd ***c, char ***envi, char ***arg, char **tmp);
void				dad(int **tube, t_cmd **cmd,
char **environnement, char **arguments);
void				ft_exec_cmd(t_cmd *cmd,
char **arg, char **envi, char *path);
void				signal_quit(int sig);
void				signal_prevent(int sig);
int					power_of_ten(int n);
int					size_int(int n);
int					check_char(char *s, char c);
void				printer(int i, char **result, t_cmd *cmd, int opt);
int					check_space_after_dollar(char *line);
void				clean_com(char **cmd, t_cmd *new_cmd,
char *tmp, char **tmp2);
void				redirect(int tube[2], t_cmd *cmd);
void				print_cmd_not_found(t_cmd *cmd);
int					print_cd_error(char *s);
void				ft_print(char *str, int size, t_cmd *cmd, int i);
void				free_split(char **s);
void				free_data();
void				free_cmd(t_cmd *lst_cmd);
void				free_hist(t_hist *h);
void				clean_input(char **path);
void				get_empty_pipe(char **cmd);
int					print_error_unexpected(char c);
int					check_error_unexpected(char *s);
void				clean_cmd(char **cmd);
int					print_error_nl_expected();
int					check_red(char *line);
void				exept_case(char **cmd, t_cmd *new_cmd);
void				delete_quote(char **arg);
int					delete_quote2(char **s, int i, char c);
void				signal_exit(int sig);
int					ft_parse(t_cmd *new_cmd, char *cmd, int i, int size);
char				*parse_env(t_env *env, char *line);
int					get_output(t_cmd *new_cmd, char **cmd, int i, int size);
void				input_case(int i, char **tmp, t_cmd *new_cmd, char **path);
void				get_fd(t_cmd *new_cmd, char **cmd);
char				*get_path(char *str);
int					open_file(char *str, int opt);
void				clean_fdout(t_list **fd);
void				get_cmd(t_cmd *new_cmd, char *cmd);
int					get_input(t_cmd *new_cmd, char *cmd, int i, int size);
void				get_arg(char **arg, char *str);
int					is_cmd_write(t_cmd *cmd);
char				*ft_strrstr(char *str, char *to_find);
void				pwd(t_data *data, char **result, t_cmd *cmd);
int					echo(char *input, char **result, t_cmd *cmd);
int					export(t_env *env, char *s, char **result, t_cmd *cmd);
void				unset(t_env *env, char *s);
int					env(t_env *envi, char **result, t_cmd *cmd, int print);
int					cd(char *s);
int					command_var_env(t_env *env,
t_env *env_w, char *line, t_cmd *c);
char				*get_env_value(t_env *env, char *name);
int					switch_to_export(t_env *env, t_env *env_w, char *s);
void				free_list_env(t_env *env);
void				free_list_export(t_env *env);
int					check_char(char *s, char c);
int					create_order_env(t_env *en, char **result, t_cmd *cmd);
int					size_var_env_not_found(char *line);
int					check_var_env_return(char *line);
int					export_no_quote(t_env *tmp, char *s, int size, int j);
int					export_quoted(t_env *tmp, char *s, int size, int j);
int					check_cd_path(char *s);
int					go_there(char *s);
int					new_pwd(char *p, char *s);
int					copy_old_pwd();
char				*parsing_file(char ***environnement,
char ***arguments, char **tmp, t_cmd *cmd);
char				*get_path_bin(t_cmd *cmd);
char				*check_dir(char *path, int *j, t_cmd *cmd);
char				**get_arguments(char *path, char *arg);
char				*get_name(char *path);
void				find_path(t_data *data);
void				ft_lstadd_back_cmd(t_cmd *new);
void				ft_lstadd_front_cmd(t_data *data, t_cmd *new);
int					ft_lstadd_front_hist(t_data *data, char *line);
char				**ft_split_shell(char *str, char charset);
char				**ft_split_sh(char *str, char charset);
char				*ft_strchr_shell(char const *s, int c);
void				ft_init_tab(int	*tab, int len);
int					check_variable_env(t_env *env, char *s, int equal);
int					check_equal(char *s);
void				pipe_in(int tube[2], t_cmd *cmd);
void				pipe_out(int tube[2]);
void				free_input_error(t_cmd *cmd, char *path, char **tmp);
void				start_input(char **tmp, char **path);
void				sigsig(void);
int					look_for_back_slash(char **result, int a);
int					export_env_w(t_env *tmp, char *s);
char				*get_cmd_n_found(t_cmd *cmd);
int					check_arg_not_found(char *s);
int					check_quote_export(char **s);
char				*env_question_found(char **line);
void				start_parse(char *cmd, char **tmp);
void				ft_exit_d(int ex, char *line);
int					n_inside_q(char *s, int i);
int					check_err(char *str);
int					check_err_bis(char *str);
void				direction_cd(char **s);
int					ft_isdigit(int c);
void				make_quote_great_again(char **s);
void				dupdup(t_cmd *new_cmd, char **tmp, char *cmd);
void				cd2(char *s, char *save, int i, int j);

#endif
