/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 11:20:55 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/16 18:15:38 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void			find_path(t_data *data)
{
	char		tmp[1000];

	ft_bzero(tmp, 1000);
	getcwd(tmp, 1000);
	ft_strlcpy(data->path, tmp, 1000);
}

void			pwd(t_data *data, char **result, t_cmd *cmd)
{
	find_path(data);
	*result = data->path;
	ft_print(*result, ft_strlen(*result), cmd, 2);
	g_data->ret = 0;
}
