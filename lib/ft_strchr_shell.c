/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_shell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:15:28 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/16 18:44:32 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int				ft_is_sep(char *str, char c2, int i)
{
	if (i > 0 && str[i - 1] == 92)
		return (0);
	if (str[i] == c2 && n_inside_q(str, i) == 0)
		return (1);
	return (0);
}

char			*ft_strchr_shell(char const *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	while (tmp[i] != '\0')
	{
		if (ft_is_sep((char *)s, c, i))
			return (&tmp[i]);
		i++;
	}
	if (ft_is_sep((char *)s, c, i))
		return (&tmp[i]);
	return (NULL);
}
