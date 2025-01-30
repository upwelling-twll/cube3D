#include "./inc/execution.h"

int	main(int argc, char *argv[])
{
	t_game_data	*initData;

	// argv[1] = "file.cub";
	initData = NULL;
	if (argc == 2) //replace to argc == 2
	{
		if (!verify_file(argv[1]))
			return(exit_program("Verify file - NOK\n exiting Cube3D", initData));
		if (!(parsing(argv[1], &initData)))
			return(exit_program("Parsing - NOK\n exiting Cube3D", initData));
		if (!validation(&initData))
			return(exit_program("Validation - NOK\n exiting Cube3D", initData));
		if (!execute(&initData))
		{
			printf("\n\n--------------------------------------------------------\n\nmy turn plz\n\n");
			printf("map height:	%d\nmap width:	%d\n\n", initData->map_height, initData->map_widht);
			printf("player x:	%f\nplayer y:	%f\n\n", initData->sp_x, initData->sp_y);
			printf("player's angle:	%f\n\n", initData->angle);
			printf("here is the map:\n\n");
			int i = -1;
			while (++i < initData->map_height)
			printf("%s\n", initData->mapLines[i]);
			printf("\n\n--------------------------------------------------------\n\n");
			return(exit_program("Execution -NOK\n exiting Cube3D", initData));
		}
	}
	else
		return(exit_program("Program expects 1 parametor: example.cub", initData));
	exit_program("Normal program exit", initData);
	return (1);
}
