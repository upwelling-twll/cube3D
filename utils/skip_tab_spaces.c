/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_tab_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:25:49 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/19 17:26:00 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

bool	is_eof(char c)
{
	if (c == '\0')
		return (true);
	else
		return (false);
}

bool	is_tab_or_space(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	else
		return (false);
}

bool	is_end_of_line(char c)
{
	if (c == '\0')
		return (true);
	else
		return (false);
}

char	*skip_non_spaces(char *line)
{
	if (!is_end_of_line(*line))
	{
		while (*line && !is_tab_or_space(*line))
			line++;
	}
	return (line);
}

char	*skip_tab_spaces(char *line)
{
	if (!is_end_of_line(*line))
	{
		while (is_tab_or_space(*line))
			line++;
	}
	return (line);
}
