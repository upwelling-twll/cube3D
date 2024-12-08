/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:49:49 by nmagdano          #+#    #+#             */
/*   Updated: 2023/10/05 18:02:01 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_idnumlen(int num, int flag)
{
	int	i;

	i = 0;
	if (num == -2147483648)
		return (11);
	if (num < 0)
		num = num * (-1);
	if (flag > 0 || num == 0)
		i++;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_print_d(int str)
{
	int	flag;

	flag = 0;
	if (str < 0)
		flag++;
	ft_putnbr_int(str);
	return (ft_idnumlen(str, flag));
}
