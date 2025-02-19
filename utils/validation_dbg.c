/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_dbg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:13:11 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/18 17:13:37 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	print_validation_map(char **mapLines)
{
	int	i;

	i = 0;
	if (!mapLines)
	{
		printf("	*** Empty map ***\n");
		return ;
	}
	while (mapLines[i] != NULL)
	{
		printf("%s$\n", mapLines[i]);
		i++;
	}
}
