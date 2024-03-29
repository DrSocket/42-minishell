/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 13:42:05 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/16 18:15:59 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			get_output(t_cmd *new_cmd, char **cmd, int i, int size)
{
	get_fd(new_cmd, cmd);
	if (i < size - 1)
		new_cmd->output = PIPE;
	else if (i == size - 1 && ft_lstsize(new_cmd->fd_out) >= 1)
		new_cmd->output = STDOUT;
	return (0);
}

void		get_fd(t_cmd *new_cmd, char **cmd)
{
	char		**tmp;
	char		*temp;
	int			i;
	int			fd;
	char		*path;

	exept_case(cmd, new_cmd);
	tmp = ft_split_sh(*cmd, '>');
	i = 1;
	while (tmp[i])
	{
		input_case(i, tmp, new_cmd, &path);
		temp = ft_strtrim(tmp[i], " >");
		if (!(ft_strchr(tmp[i], '<')))
			path = get_path(temp);
		free(temp);
		if (tmp[i][0] == '>' && tmp[i][1] != '>')
			fd = open_file(path, 1);
		else
			fd = open_file(path, 2);
		ft_lstadd_back(&new_cmd->fd_out, ft_lstnew_malloc(&fd, sizeof(fd)));
		free(path);
		i++;
	}
	free_split(tmp);
}

void		exept_case(char **cmd, t_cmd *new_cmd)
{
	char	*tmp;
	char	*tmp3;
	char	**tmp2;
	int		fd;

	fd = 0;
	tmp = ft_strtrim(*cmd, " ");
	if (tmp[0] && tmp[0] == '>')
	{
		while (tmp[fd] == '>')
			fd++;
		tmp2 = ft_split(&tmp[fd], ' ');
		free(tmp);
		tmp3 = ft_strtrim(tmp2[0], " ");
		tmp = get_path(tmp3);
		free(tmp3);
		if (fd == 2)
			fd = open_file(tmp, 1);
		else
			fd = open_file(tmp, 2);
		ft_lstadd_back(&new_cmd->fd_out, ft_lstnew_malloc(&fd, sizeof(fd)));
		clean_com(cmd, new_cmd, tmp, tmp2);
	}
	else
		free(tmp);
}

void		clean_com(char **cmd, t_cmd *new_cmd, char *tmp, char **tmp2)
{
	int		fd;

	fd = ft_strlen(tmp2[0]);
	free(tmp);
	tmp = ft_strdup(ft_strnstr(*cmd, tmp2[0], 1000) + fd);
	free(*cmd);
	*cmd = ft_strtrim(tmp, " ");
	if ((*cmd)[0] == 0)
	{
		new_cmd->exept_case = 1;
		free(*cmd);
		*cmd = ft_strdup("yolo");
	}
	free(tmp);
	free_split(tmp2);
	if ((*cmd)[0] == '>')
		exept_case(cmd, new_cmd);
}

void		input_case(int i, char **tmp, t_cmd *new_cmd, char **path)
{
	char		**tmp2;

	if (ft_strchr(tmp[i], '<'))
	{
		get_input(new_cmd, tmp[i], 0, 0);
		tmp2 = ft_split_shell(tmp[i], '<');
		*path = get_path(ft_strtrim(tmp2[0], " >"));
		free_split(tmp2);
	}
}
