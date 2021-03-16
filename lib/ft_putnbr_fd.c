/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 17:57:03 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/16 18:44:19 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	k;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		k = -n;
	}
	else
		k = n;
	if (k >= 10)
		ft_putnbr_fd(k / 10, fd);
	ft_putchar_fd(k % 10 + '0', fd);
}
