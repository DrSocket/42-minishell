/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_suite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:40:33 by jfeuilla          #+#    #+#             */
/*   Updated: 2021/03/16 18:40:33 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int		command_var_env2(char *nl)
{
	free(nl);
	return (1);
}

int				command_var_env(t_env *env,
		t_env *env_w, char *line, t_cmd *cmd)
{
	t_env	*tmp;
	char	*nl;

	tmp = env_w;
	nl = get_cmd_n_found(cmd);
	if (check_char(line, '=') == 0 || check_arg_not_found(nl) == 1)
	{
		free(nl);
		return (-1);
	}
	if (check_variable_env(env, line, check_char(nl, '=')) == 1 ||
		check_variable_env(env_w, line, check_char(nl, '=')) == 1)
	{
		g_data->ret = 0;
		free(nl);
		return (0);
	}
	while (tmp->next)
		tmp = tmp->next;
	if (export_env_w(tmp, nl) == 1)
		return (command_var_env2(nl));
	free(nl);
	return (0);
}

char			*get_env_value(t_env *env, char *name)
{
	t_env		*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) != 0)
			tmp = tmp->next;
		else
			return (tmp->value);
	}
	return (0);
}
