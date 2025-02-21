/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:44:10 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/21 17:44:11 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

bool	good_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd > 2)
		return (true);
	else if (fd >= 0 && fd <= 2)
	{
		print_error(file_path, "File error: can not read from standard \
		 stdin/stdout/stderr");
		close(fd);
		return (false);
	}
	else if (fd < 0)
	{
		print_error(file_path, "File error: this file can not be read from");
		return (false);
	}
	return (false);
}
