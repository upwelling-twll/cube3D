/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_dbg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:26:25 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/19 17:26:26 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	print_validation_map(char **mapLines, char *map_name)
{
	int	i;

	i = 0;
	printf("\n		~%s map~	 \n", map_name);
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
