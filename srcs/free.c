/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:42:09 by jfeuilla          #+#    #+#             */
/*   Updated: 2021/03/16 18:42:09 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		free_cmd(t_cmd *lst_cmd)
{
	t_cmd *tmp;
	t_cmd *tmp2;

	tmp = lst_cmd;
	while (tmp)
	{
		ft_lstclear(&tmp->fd_out, &free);
		free(tmp->arg);
		if (tmp->cmd == 8 || tmp->cmd == 9)
		{
			free(tmp->cmd_n_found);
			free(tmp->cmd_temp);
		}
		if (tmp->cmd == 7)
			free(tmp->result);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

void		free_input_error(t_cmd *cmd, char *path, char **tmp)
{
	print_cmd_not_found(cmd);
	free(path);
	free_split(tmp);
	ft_lstclear(&cmd->fd_out, &free);
	if (cmd->cmd == 8 || cmd->cmd == 9)
	{
		free(cmd->cmd_n_found);
		free(cmd->cmd_temp);
	}
	free(cmd);
}

void		free_hist(t_hist *h)
{
	t_hist *tmp;
	t_hist *tmp2;

	tmp = h;
	while (tmp)
	{
		free(tmp->line);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	free(tmp);
}

void		free_data(void)
{
	free_list_env(g_data->lst_env);
	free_list_env(g_data->lst_env_waiting);
	free_cmd(g_data->lst_cmd);
	free_hist(g_data->historic);
	free(g_data->pipe);
}
