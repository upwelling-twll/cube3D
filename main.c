/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssiddiqu <ssiddiqu@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:59:14 by ssiddiqu          #+#    #+#             */
/*   Updated: 2025/02/19 18:07:23 by ssiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/execution.h"

int	main(int argc, char *argv[])
{
	t_game_data	*initdata;

	initdata = NULL;
	if (argc == 2)
	{
		if (!verify_file(argv[1]))
			return (exit_program("Verify file NOK\n exiting Cube3D", initdata));
		if (!(parsing(argv[1], &initdata)))
			return (exit_program("Parsing - NOK\n exiting Cube3D", initdata));
		if (!validation(&initdata))
			return (exit_program("Validation NOK\n exiting Cube3D", initdata));
		if (!execute(&initdata))
			return (exit_program("Execution NOK\n exiting Cube3D", initdata));
	}
	else
		return (exit_program("Program needs 1 parameter: ex.cub", initdata));
	exit_program("Normal program exit", initdata);
	return (1);
}
