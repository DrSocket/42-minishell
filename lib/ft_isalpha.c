/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <ylegzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 18:07:18 by ylegzoul          #+#    #+#             */
/*   Updated: 2020/05/22 18:07:21 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int c)
{
	if (c != '\0')
	{
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
			return (1);
	}
	return (0);
}
