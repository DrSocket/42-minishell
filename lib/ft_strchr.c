/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:15:28 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/16 18:44:36 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(char const *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == c)
			return (&tmp[i]);
		i++;
	}
	if (tmp[i] == c)
		return (&tmp[i]);
	return (NULL);
}
