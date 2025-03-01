/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:59:14 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/03/01 13:46:08 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/execution.h"

int	main(int argc, char *argv[])
{
	t_game_data	*initdata;

	initdata = NULL;
	if (argc == 2)
	{
		if (!verify_file(argv[1]))
			return (exit_program("Error:Verify file NOK\n", initdata));
		if (!(parsing(argv[1], &initdata)))
			return (exit_program("Error:Parsing - NOK\n", initdata));
		if (!validation(&initdata))
			return (exit_program("Error:Validation NOK\n", initdata));
		if (!execute(&initdata))
			return (exit_program("Error:Execution NOK\n", initdata));
	}
	else
		return (exit_program("Error:Program needs 1 param:ex.cub", initdata));
	exit_program("Normal program exit", initdata);
	return (1);
}
