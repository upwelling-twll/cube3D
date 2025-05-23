/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dbg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:24:14 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/19 17:24:19 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	print_parsed_textures(t_parsed_lines *initLines)
{
	t_parsed_lines	*cplst;

	printf("\n		~Parsed initList~	 \n");
	if (!initLines)
	{
		printf("	*** Empty initList ***\n");
		return ;
	}
	cplst = initLines;
	while (cplst != NULL)
	{
		printf("line[%i]:%s$", cplst->id, cplst->line);
		cplst = cplst->next;
	}
}

void	print_parsed_map(char **mapLines)
{
	int	i;

	i = 0;
	printf("\n		~Parsed mapLines~	 \n");
	if (!mapLines)
	{
		printf("	*** Empty mapLines ***\n");
		return ;
	}
	while (mapLines[i] != NULL)
	{
		printf("%s$", mapLines[i]);
		i++;
	}
}
