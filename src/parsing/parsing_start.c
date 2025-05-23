/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:43:57 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/21 17:44:05 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

void	init_txtr(t_txtr *newtxt)
{
	newtxt->fd = -1;
	newtxt->path = NULL;
	newtxt->status = false;
	newtxt->type = NULL;
}

void	init_structs(t_game_data **initData)
{
	init_txtr(&(*initData)->no_path);
	init_txtr(&(*initData)->so_path);
	init_txtr(&(*initData)->we_path);
	init_txtr(&(*initData)->ea_path);
	(*initData)->floor.status = false;
	(*initData)->celling.status = false;
	(*initData)->maplines = NULL;
}

bool	parsing(char *path, t_game_data **initData)
{
	int		fd;
	char	*map_line;

	if (!path)
		return (false);
	*initData = malloc(sizeof(t_game_data));
	init_structs(initData);
	map_line = NULL;
	if (!(*initData))
		return (print_error(NULL, "Parsing:can not create initData"));
	fd = open(path, O_RDONLY);
	if (parse_textures(fd, *initData, &map_line))
	{
		if (parse_map(path, fd, *initData, map_line))
		{
			close(fd);
			return (true);
		}
	}
	close(fd);
	if (map_line)
		free(map_line);
	return (false);
}
