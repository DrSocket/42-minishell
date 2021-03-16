/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 08:06:48 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/16 18:44:00 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*temp;
	t_list		*temp2;

	temp2 = *lst;
	temp = NULL;
	if (lst == NULL || *lst == NULL)
		return ;
	while (temp2)
	{
		if (temp2->next)
			temp = temp2->next;
		else
			temp = NULL;
		(*del)(temp2->content);
		free(temp2);
		temp2 = temp;
	}
	*lst = NULL;
}
