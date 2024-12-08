/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:49:49 by nmagdano          #+#    #+#             */
/*   Updated: 2023/10/05 18:02:01 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	res_len_p(unsigned long long num)
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

void	ft_put_digit_p(int num, int key)

{
	char	asc;

	if (num < 10)
		asc = num + '0';
	else
	{
		if (key)
			asc = num - 10 + 'A';
		else
			asc = num - 10 + 'a';
	}
	write (1, &asc, 1);
}

void	ft_hex_rec_p(unsigned long long num, int key)
{
	if (num / 16 != 0)
	{
		ft_hex_rec_p (num / 16, key);
		ft_put_digit_p(num % 16, key);
	}
	else
		ft_put_digit_p(num % 16, key);
}

int	thex_p(unsigned long long num, int key)
{
	ft_hex_rec_p(num, key);
	return (res_len_p(num));
}

int	ft_print_p(unsigned long long num)
{
	int	i;

	i = 0;
	if (num == 0)
	{
		write (1, "0x0", 3);
		return (3);
	}
	write (1, "0x", 2);
	i = 2 + thex_p(num, 0);
	return (i);
}
