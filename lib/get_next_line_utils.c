/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:55:04 by jfeuilla          #+#    #+#             */
/*   Updated: 2021/03/16 18:55:04 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_subnull(void)
{
	char *ret;

	if (!(ret = malloc(sizeof(char))))
		return (NULL);
	ret[0] = '\0';
	return (ret);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char		*ret;
	int			i;
	int			j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ret = (void *)malloc(sizeof(char) * (i + j + 1));
	if (ret == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	size_t			j;

	j = 0;
	s2 = 0;
	while (s[j] && j < start)
		j++;
	if (j != start)
		return (ft_subnull());
	j = 0;
	while (s[start + j] && j < len)
		j++;
	if (!(s2 = malloc(j + 1)))
		return (0);
	j = 0;
	while (s[start + j] && j < len)
	{
		s2[j] = s[j + start];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}
