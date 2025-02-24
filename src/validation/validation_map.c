/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:48:27 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/21 17:48:28 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/validation.h"

bool	has_one_hero(char **lmap)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 0;
	j = 0;
	if (!lmap)
		return (false);
	while (lmap[i])
	{
		j = 0;
		while (lmap[i][j])
		{
			if (is_hero(lmap[i][j]))
				n++;
			j++;
		}
		i++;
	}
	if (n == 1 && good_pos(lmap))
		return (true);
	return (false);
}

bool	is_wall(char *line)
{
	int	i;
	int	wall;

	i = 0;
	wall = 0;
	if (!line)
		return (false);
	while (line[i])
	{
		if (line[i] == '1')
			wall++;
		if (line[i] == '\n' && wall == 0)
			return (false);
		if (line [i] != '1' && line[i] != ' ' && line[i] != '\n')
			return (false);
		i++;
	}
	if (wall > 0)
		return (true);
	return (print_message("Error:Map wall invalid"), false);
}

bool	replace_sp_to_x(t_game_data **idata, int rows)
{
	char	**nmap;
	char	**map;
	int		max_len;

	max_len = 0;
	map = (*idata)->maplines;
	if (!idata || !(*idata)->maplines)
		return (false);
	max_len = get_maxlen(map);
	if (!max_len)
		return (false);
	(*idata)->map_height = rows;
	(*idata)->map_widht = max_len;
	nmap = replace_spaces(map, max_len, rows);
	if (!nmap)
		return (false);
	clean_map((*idata)->maplines);
	(*idata)->maplines = nmap;
	return (true);
}

bool	is_valid_map(t_game_data **idata, char **lmap)
{
	int		lnum;
	char	**nmap;

	nmap = NULL;
	lnum = 0;
	if (!(has_one_hero(lmap)))
		return (print_message("Error:Player issue"), false);
	if (!is_wall(lmap[0]))
		return (print_message("Error:First map line is NOT wall"), false);
	nmap = remove_last_nlsp(idata);
	if (!nmap)
		return (print_message("Error:Map error"), false);
	lnum = get_array_size((*idata)->maplines);
	if (!is_wall(nmap[lnum - 1]))
		return (print_message("Error:Walls check failed"), false);
	if (!(replace_sp_to_x(idata, lnum)))
		return (print_message("Error:Saving map error"), false);
	if (!check_walls((*idata)->maplines, (*idata)->map_height,
			(*idata)->map_widht))
		return (print_message("Error:Map spaces check failed"), false);
	return (true);
}
