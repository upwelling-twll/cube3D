/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:27:17 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/19 17:34:50 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/validation.h"

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
