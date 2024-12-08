/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:49:49 by nmagdano          #+#    #+#             */
/*   Updated: 2023/10/05 18:02:01 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	res_len(unsigned int num)
{
	int	len;

	len = 1;
	while (num / 16)
	{
		num /= 16;
		len++;
	}
	return (len);
}

void	ft_put_digit(unsigned int num, int key)
{
	char	asc;

	if (num > 9)
	{
		if (key)
			asc = num - 10 + 'A';
		else
			asc = num - 10 + 'a';
	}
	else
		asc = num + '0';
	write (1, &asc, 1);
}

void	ft_hex_rec(unsigned int num, int key)
{
	if (num / 16 != 0)
	{
		ft_hex_rec (num / 16, key);
		ft_put_digit(num % 16, key);
	}
	else
		ft_put_digit(num % 16, key);
}

int	thex(unsigned int num, int key)
{
	ft_hex_rec(num, key);
	return (res_len(num));
}
