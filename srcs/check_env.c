/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:39:15 by jfeuilla          #+#    #+#             */
/*   Updated: 2021/03/16 18:39:15 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	check_variable_env2(t_env *tmp, char *s, int size, int i)
{
	free(tmp->value);
	size++;
	while (s[i + size])
		i++;
	if (!(tmp->value = malloc(sizeof(char) * (i + 1))))
		return (-1);
	tmp->value[i] = '\0';
	while (--i >= 0)
		tmp->value[i] = s[i + size];
	return (0);
}

int			check_variable_env(t_env *env, char *s, int equal)
{
	t_env		*tmp;
	int			size;
	int			i;

	tmp = env;
	size = 0;
	i = 0;
	while (s[size] && s[size] != '=')
		size++;
	while (tmp)
	{
		if (ft_strncmp(s, tmp->name, size) != 0)
			tmp = tmp->next;
		else if (ft_strlen(tmp->name) != size)
			tmp = tmp->next;
		else if (equal == 1)
		{
			check_variable_env2(tmp, s, size, i);
			return (1);
		}
		else if (equal == 0 && ft_strlen(tmp->name) > 0)
			return (1);
	}
	return (0);
}
