/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_colours.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:56:32 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/21 17:58:03 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/validation.h"

char	*set_colour(char *line, int *rgb_compon)
{
	int	n;

	if (!line)
		return (NULL);
	n = ft_atoi(line);
	*rgb_compon = n;
	line = skip_digits(line);
	line = skip_comma(line);
	line = skip_tab_spaces(line);
	return (line);
}

bool	save_rgb(t_game_data **idata, char *line, char *type)
{
	if (!(*idata) || !line || !type)
		return (false);
	if (ft_strncmp(type, "F", 1) == 0)
	{
		line = set_colour(line, &(*idata)->floor.red);
		line = set_colour(line, &(*idata)->floor.green);
		line = set_colour(line, &(*idata)->floor.blue);
		(*idata)->floor.status = true;
		return (true);
	}
	else if (ft_strncmp(type, "C", 1) == 0)
	{
		line = set_colour(line, &(*idata)->celling.red);
		line = set_colour(line, &(*idata)->celling.green);
		line = set_colour(line, &(*idata)->celling.blue);
		(*idata)->celling.status = true;
		return (true);
	}
	return (false);
}
