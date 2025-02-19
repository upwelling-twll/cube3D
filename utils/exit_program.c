/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:23:57 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/19 17:52:00 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	clean_elem_lines(t_parsed_lines **initLines)
{
	t_parsed_lines	*tmp;

	if ((!initLines) || !(*initLines))
		return ;
	tmp = (*initLines)->next;
	while ((*initLines) != NULL)
	{
		free((*initLines)->line);
		tmp = (*initLines)->next;
		free((*initLines));
		(*initLines) = tmp;
	}
	free (initLines);
	initLines = NULL;
}

bool	exit_textures(char *line)
{
	if (line)
		free(line);
	return (false);
}

void	clean_textures(t_game_data *data)
{
	if (data->no_path.status == true)
	{
		free(data->no_path.type);
		free(data->no_path.path);
	}
	if (data->so_path.status == true)
	{
		free(data->so_path.type);
		free(data->so_path.path);
	}
	if (data->we_path.status == true)
	{
		free(data->we_path.type);
		free(data->we_path.path);
	}
	if (data->ea_path.status == true)
	{
		free(data->ea_path.type);
		free(data->ea_path.path);
	}
}

int	exit_program(char *text, t_game_data *initData)
{
	if (text)
		printf("%s\n", text);
	if (initData && initData->initlines)
		clean_elem_lines(initData->initlines);
	if (initData && initData->maplines)
		clean_map(initData->maplines);
	if (initData)
		clean_textures(initData);
	if (initData)
		free(initData);
	return (1);
}

void	clean_map(char **map)
{
	int	i;

	i = 0;
	if (!map || !map[0])
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return ;
}
