/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:49:49 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/02 22:59:18 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, ssize_t len)
{
	char	*cp;
	ssize_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	if (ft_strlen_sst(s1) < len)
		return (NULL);
	cp = malloc(len + 1);
	if (!cp)
		return (NULL);
	while (i != len)
	{
		*(char *)(cp + i) = *(char *)(s1 + i);
		i++;
	}
	*(char *)(cp + i) = '\0';
	return (cp);
}
