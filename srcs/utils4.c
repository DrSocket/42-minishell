/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 10:43:49 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/16 18:15:01 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		dupdup(t_cmd *new_cmd, char **tmp, char *cmd)
{
	new_cmd->cmd_n_found = ft_strdup(tmp[0]);
	new_cmd->cmd_temp = ft_strdup(cmd);
	delete_quote(&new_cmd->cmd_n_found);
	new_cmd->cmd = EXEC;
}

char		*parsing_file(char ***envi, char ***arg, char **tmp, t_cmd *cmd)
{
	env(g_data->lst_env, tmp, cmd, 0);
	*envi = ft_split(*tmp, '\n');
	free(*tmp);
	*tmp = NULL;
	if (!(*tmp = get_path_bin(cmd)))
	{
		free_split(*envi);
		cmd->cmd = NOTFOUND;
	}
	*arg = get_arguments(*tmp, cmd->arg);
	return (0);
}
