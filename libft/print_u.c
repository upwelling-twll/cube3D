/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:49:49 by nmagdano          #+#    #+#             */
/*   Updated: 2023/10/05 18:02:01 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_uint(unsigned int n)
{
	if (n >= 10)
		ft_putnbr_int(n / 10);
	ft_putcharlen(n % 10 + '0');
}

int	ft_unumlen(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		i++;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_print_u(unsigned int num)
{
	ft_putnbr_uint(num);
	return (ft_unumlen(num));
}
