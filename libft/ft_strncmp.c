/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:46:12 by nmagdano          #+#    #+#             */
/*   Updated: 2023/07/09 13:46:14 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i != n - 1 && *(str1 + i) != '\0')
	{
		if (*(str1 + i) == *(str2 + i))
			i++;
		else
			return ((unsigned char)*(str1 + i) - (unsigned char) *(str2 + i));
	}
	if (*(str1 + i) == *(str2 + i))
		return (0);
	return ((unsigned char)*(str1 + i) - (unsigned char)*(str2 + i));
}
