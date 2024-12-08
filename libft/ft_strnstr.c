/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:47:01 by nmagdano          #+#    #+#             */
/*   Updated: 2023/09/12 16:22:36 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *strA, const char *strB, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!*strB)
		return ((char *)strA);
	if (!strA)
		return (NULL);
	while (strA[i])
	{
		j = 0;
		while (strA[i] == strB[j] && strA[i] && i < len)
		{
			i++;
			j++;
		}
		if (!strB[j])
			return ((char *)&strA[i - j]);
		i = (i - j) + 1;
	}
	return (NULL);
}
