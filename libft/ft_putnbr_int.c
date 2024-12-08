/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:49:49 by nmagdano          #+#    #+#             */
/*   Updated: 2024/03/02 13:57:10 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_int(int n)
{
	if (n == -2147483648)
	{
		ft_putcharlen('-');
		ft_putnbr_int(214748364);
		ft_putcharlen('8');
		return ;
	}
	if (n < 0)
	{
		n = n * (-1);
		ft_putcharlen('-');
	}
	if (n >= 10)
		ft_putnbr_int(n / 10);
	ft_putcharlen(n % 10 + '0');
}
