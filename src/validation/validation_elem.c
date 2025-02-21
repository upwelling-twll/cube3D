/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:46:51 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/21 17:57:36 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/validation.h"

char	*remove_back_spaces(char *input)
{
	int		len;
	int		i;
	char	*path;

	i = 0;
	len = ft_strlen(input);
	while (i < len && !(is_tab_or_space(input[i])) && input[i] != '\n')
		i++;
	if (i < 4)
		return (NULL);
	path = malloc(sizeof(char) * i + 1);
	if (!path)
		return (NULL);
	len = 0;
	while (len < i)
	{
		path[len] = input[len];
		len++;
	}
	path[len] = '\0';
	return (path);
}

bool	correct_path(char *line)
{
	char	*cpline;

	if (!line || is_eof(*line) || is_empty_line(line))
		return (false);
	cpline = remove_back_spaces(line);
	if (cpline && verify_file_xpm(cpline))
	{
		free(cpline);
		return (true);
	}
	free(cpline);
	return (false);
}

bool	correct_colours(char *cpline)
{
	int		i;
	int		colour;
	char	*line;

	i = 0;
	line = cpline;
	colour = -1;
	if (!line || is_eof(*line) || is_empty_line(line))
		return (false);
	while (i < 3 && *line)
	{
		colour = ft_atoi(line);
		if (colour < 0 || colour > 255)
			return (false);
		i++;
		line = skip_digits(line);
		if (i == 3)
			break ;
		line = skip_tab_spaces(line);
		if (line && is_comma(*line))
			line = skip_comma(line);
		else
			return (false);
		line = skip_tab_spaces(line);
	}
	if (i == 3 && is_empty_line(line))
		return (true);
	return (false);
}

bool	save_txtr(t_game_data **idata, char *path, char *type)
{
	char	*cppath;

	if (!(*idata) || !path || !type)
		return (false);
	cppath = remove_back_spaces(path);
	if (!cppath)
		return (false);
	if (ft_strncmp(type, "NO", 2) == 0)
		return (save_txt_data(&((*idata)->no_path), cppath, type));
	else if (ft_strncmp(type, "SO", 2) == 0)
		return (save_txt_data(&((*idata)->so_path), cppath, type));
	else if (ft_strncmp(type, "WE", 2) == 0)
		return (save_txt_data(&((*idata)->we_path), cppath, type));
	else if (ft_strncmp(type, "EA", 2) == 0)
		return (save_txt_data(&((*idata)->ea_path), cppath, type));
	return (false);
}

bool	is_unique(t_game_data **d, char *t)
{
	if (!ft_strncmp(t, "NO", 2) && (*d)->no_path.status == true)
		return (false);
	else if (!ft_strncmp(t, "SO", 2) && (*d)->so_path.status == true)
		return (false);
	else if (!ft_strncmp(t, "WE", 2) && (*d)->we_path.status == true)
		return (false);
	else if (!ft_strncmp(t, "EA", 2) && (*d)->ea_path.status == true)
		return (false);
	else if (!ft_strncmp(t, "F", 2) && (*d)->floor.status == true)
		return (false);
	else if (!ft_strncmp(t, "C", 2) && (*d)->celling.status == true)
		return (false);
	else
		return (true);
}

bool	is_etoken(char *cpline, char **etype)
{
	char	*types[6];
	int		etlen;

	types[0] = "NO";
	types[1] = "SO";
	types[2] = "WE";
	types[3] = "EA";
	types[4] = "F";
	types[5] = "C";
	etlen = 0;
	if (!cpline || is_eof(*cpline) || is_empty_line(cpline))
		return (false);
	etlen = is_etoken_len(cpline);
	if (etlen == 2)
		*etype = is_texture(cpline, types);
	else if (etlen == 1)
		*etype = is_rgb(cpline, types);
	else
		return (false);
	if (!(*etype))
		return (false);
	return (true);
}
