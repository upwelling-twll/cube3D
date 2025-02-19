/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:23:40 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/19 17:35:02 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

bool	iswall(char c)
{
	if (c == '1' || c == 'x')
		return (true);
	return (false);
}

int	get_isign(float n)
{
	if (n < 0.0f)
	{
		if (n > -0.000001)
			return (0);
		else
			return (-1);
	}
	else
	{
		if (n < 0.000001f)
			return (0);
		else
			return (1);
	}
}

int	get_array_size(char **array)
{
	int	i;

	i = 0;
	if (!array || !array[0])
		return (0);
	while (array[i])
		i++;
	return (i);
}
