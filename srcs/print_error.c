/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 10:55:36 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/16 18:15:43 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		print_cmd_not_found(t_cmd *cmd)
{
	cmd->nb_cmd = g_data->step_cmd;
	if (cmd->exept_case)
		return ;
	g_data->ret = 127;
	write(2, "minishell: ", 11);
	ft_putnbr_fd(cmd->nb_cmd, 2);
	write(2, ": ", 2);
	if (cmd->cmd == 8)
		write(2, cmd->cmd_n_found, ft_strlen(cmd->cmd_n_found));
	else
	{
		write(2, "file not found\n", 15);
		return ;
	}
	if (cmd->arg && cmd->arg[0] != 0)
	{
		write(2, " ", 1);
		write(2, cmd->arg, ft_strlen(cmd->arg));
	}
	write(2, ": not found\n", 12);
}

int			print_cd_error(char *s)
{
	write(2, "minishell: ", 11);
	ft_putnbr_fd(g_data->step_cmd, 2);
	write(2, ": cd: can't cd to ", 18);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	g_data->ret = 2;
	return (1);
}

int			print_error_unexpected(char c)
{
	(g_data->step_cmd)++;
	write(2, "minishell: ", 11);
	ft_putnbr_fd(g_data->step_cmd, 2);
	write(2, ": Synthax error: '", 18);
	write(2, &c, 1);
	write(2, "' unexpected\n", 13);
	g_data->ret = 2;
	return (1);
}

int			print_error_nl_expected(void)
{
	(g_data->step_cmd)++;
	write(2, "minishell: ", 11);
	ft_putnbr_fd(g_data->step_cmd, 2);
	write(2, ": Synthax error: newline expected\n", 35);
	g_data->ret = 2;
	return (1);
}
