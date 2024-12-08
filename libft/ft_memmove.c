/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:44:20 by nmagdano          #+#    #+#             */
/*   Updated: 2023/07/09 13:44:22 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	n;

	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		n = (int)len - 1;
		while (n >= 0)
		{
			*(char *)(dst + n) = *(char *)(src + n);
			n--;
		}
	}
	else
	{
		n = 0;
		while (n < (int)len)
		{
			*(char *)(dst + n) = *(char *)(src + n);
			n ++;
		}
	}
	return (dst);
}
