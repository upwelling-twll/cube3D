/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:43:00 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/21 17:43:40 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

int	search_elements(char *line, t_game_data *initData, int pe)
{
	if (pe == 0)
	{
		if (!start_list(line, initData))
			return (0);
		else
			return (1);
	}
	else
	{
		if (!append_to_list(line, initData))
			return (0);
		else
			return (1);
	}
	return (0);
}

void	init_structure(t_game_data *initData)
{
	initData->initlines = (t_parsed_lines **)malloc(sizeof(t_parsed_lines *));
	*(initData->initlines) = (t_parsed_lines *)malloc(sizeof(t_parsed_lines));
	(*initData->initlines)->next = NULL;
	(*initData->initlines)->line = NULL;
	(*initData->initlines)->id = 1;
}

bool	all_elements_parsed(int pe, t_parsed_lines	*h, char *l, char **map_l)
{
	if (pe < 6 || ft_lstsize_pl(h) < 6)
	{
		print_error("Parsing intit info", "Do not have 6 lines");
		if (l)
			free(l);
		*map_l = NULL;
		return (false);
	}
	if (l)
	{
		*map_l = ft_strdup(l);
		free(l);
	}
	else
		*map_l = NULL;
	return (true);
}

bool	parse_textures(int fd, t_game_data *initData, char **map_line)
{
	char			*line;
	int				parsed_elements;
	int				minimum_elements;
	t_parsed_lines	*head;

	minimum_elements = 6;
	parsed_elements = 0;
	init_structure(initData);
	head = *initData->initlines;
	line = skip_empty_lines(fd);
	while (line && !is_eof(*line) && parsed_elements < minimum_elements)
	{
		parsed_elements += search_elements(line, initData, parsed_elements);
		if (line)
			free(line);
		line = skip_empty_lines(fd);
		*(initData->initlines) = head;
	}
	if (!all_elements_parsed(parsed_elements, head, line, map_line))
		return (exit_textures(NULL));
	return (true);
}
