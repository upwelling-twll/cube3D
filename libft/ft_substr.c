/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:46:37 by nmagdano          #+#    #+#             */
/*   Updated: 2023/07/09 13:46:37 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_getl(char const *s, unsigned int start, size_t len)
{
	size_t	strlen;

	strlen = 0;
	strlen = ft_strlen(s) - start;
	if (ft_strlen(s) - start < len)
		return (strlen);
	if (start > ft_strlen(s))
		return (0);
	if (!s)
		return (-1);
	return (len);
}

char	*ft_getsubstr(char *substr, char const *s, unsigned int start,
		size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j != start)
		j++;
	while (s[j] && i != len)
	{
		substr[i] = s[j];
		i++;
		j++;
	}
	substr[i] = 0;
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	sublen;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		substr = malloc(1);
		substr[0] = '\0';
		return (substr);
	}
	sublen = ft_getl(s, start, len);
	substr = (char *)malloc(sizeof(char) * (sublen + 1));
	if (!substr)
		return (NULL);
	ft_getsubstr(substr, s, start, sublen);
	return (substr);
}
