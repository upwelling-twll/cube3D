/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:46:31 by nmagdano          #+#    #+#             */
/*   Updated: 2023/07/09 13:46:31 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checksmb(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_checkend(char const *s1, size_t j, char const *set, size_t len)
{
	size_t	k;

	k = len;
	while (k != j)
	{
		if (ft_checksmb(s1[k - 1], set) == 1)
			k--;
		else
			return (len - k);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	j;
	size_t	len;
	size_t	extrasmb;

	j = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	while (s1[j] && ft_checksmb(s1[j], set) == 1)
		j++;
	if (j != len)
		extrasmb = ft_checkend(s1, j, set, len);
	if (j == len)
		return (ft_substr(s1, j, 0));
	return (ft_substr(s1, j, len - j - extrasmb));
}
