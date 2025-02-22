/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map_edit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:27:03 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/19 17:44:00 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/validation.h"

bool	is_comma(char c)
{
	if (c == ',')
		return (true);
	else
		return (false);
}

char	*skip_comma(char *line)
{
	if (!(is_end_of_line(*line)))
	{
		line++;
	}
	return (line);
}
