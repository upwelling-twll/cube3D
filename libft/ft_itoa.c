/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:42:21 by nmagdano          #+#    #+#             */
/*   Updated: 2023/08/28 18:54:39 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*num;

	len = ft_getlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	if (n < 0)
	{
		num[0] = '-';
		n = n * (-1);
	}
	num[len--] = '\0';
	while (n / 10 > 0)
	{
		num[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	num[len] = (n % 10) + '0';
	return (num);
}
