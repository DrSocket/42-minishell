/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:34:33 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/16 18:43:57 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list		*li;

	li = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (li->next != NULL)
		li = li->next;
	li->next = new;
}
