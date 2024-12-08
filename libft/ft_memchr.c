/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:43:54 by nmagdano          #+#    #+#             */
/*   Updated: 2023/07/09 13:43:57 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*chrloct;

	i = 0;
	chrloct = (unsigned char *)s;
	while (n--)
	{
		if (chrloct[i] == (unsigned char)c)
			return (chrloct + i);
		i++;
	}
	return (NULL);
}
