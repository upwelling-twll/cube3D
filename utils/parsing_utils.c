/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:24:31 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/19 17:26:13 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

bool	token_found(char *search, char *input)
{
	if (search && input)
	{
		if (ft_strncmp(search, input, ft_strlen(search)))
			return (false);
		else
			return (true);
	}
	else
	{
		print_message("parsing textures. token_found: \
		no input or search");
		return (false);
	}
}

void	move_line(int value, char **line)
{
	if (value > 0 && value < 10)
		*line = *(line + 1);
	else if (value > 10 && value < 100)
		*line = *(line + 2);
	else if (value > 100 && value <= 255)
		*line = *(line + 3);
}

void	clean_initdata(t_game_data *initData)
{
	if (!initData)
		return ;
	free(initData);
	printf("cleaned initData");
}

bool	is_empty_line(char *line)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!line)
		return (false);
	len = ft_strlen(line);
	while (i < len && (line[i] == ' ' || line[i] == '\n' || line[i] == '\t'))
		i++;
	if (line[i] == '\0')
		return (true);
	else
		return (false);
}

char	*skip_empty_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
	{
		while (is_empty_line(line) == true)
		{
			if (line)
				free(line);
			line = get_next_line(fd);
		}
		if (line)
			return (line);
	}
	return (NULL);
}
