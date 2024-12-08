/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:45:22 by nmagdano          #+#    #+#             */
/*   Updated: 2023/07/09 15:35:20 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*cp;
	size_t	len;

	len = ft_strlen(s1) + 1;
	cp = malloc(len);
	if (cp)
		ft_memcpy(cp, s1, len);
	return (cp);
}
