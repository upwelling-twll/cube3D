/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:23:34 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/19 17:23:35 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	print_message(char *text)
{
	printf("%s\n", text);
}

int	print_error(char *data, char *text)
{
	if (data)
		printf("%s. %s\n", data, text);
	else if (data == NULL)
		printf("%s\n", text);
	return (1);
}
