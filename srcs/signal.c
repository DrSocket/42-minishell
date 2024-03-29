/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 11:21:21 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/16 18:15:31 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	signal_prevent(int sig)
{
	if (sig == SIGINT)
	{
		g_data->ret = 130;
		write(1, "\n", 1);
		ft_print_prompt();
	}
	if (sig == SIGQUIT)
	{
		g_data->exit = 0;
		g_data->ret = 0;
	}
}

void	sigsig(void)
{
	signal(SIGINT, signal_quit);
	signal(SIGQUIT, signal_quit);
}

void	signal_quit(int sig)
{
	if (sig == SIGINT)
	{
		g_data->ret = 130;
		write(1, "\n", 1);
	}
	if (sig == SIGQUIT)
	{
		g_data->exit = 0;
		write(1, "Quit: core dumped\n", 18);
		g_data->ret = 131;
	}
}
