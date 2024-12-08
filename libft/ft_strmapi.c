/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:46:07 by nmagdano          #+#    #+#             */
/*   Updated: 2023/08/26 19:01:47 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*newstr;

	i = 0;
	if (!s || !f)
		return (NULL);
	newstr = ft_strdup(s);
	if (!newstr)
		return (NULL);
	while (s[i])
	{
		newstr[i] = (*f)(i, s[i]);
		i++;
	}
	return (newstr);
}
