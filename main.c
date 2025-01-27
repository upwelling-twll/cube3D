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
			return(exit_program("Execution -NOK\n exiting Cube3D", initData));
	}
	else
		return(exit_program("Program expects 1 parametor: example.cub", initData));
	exit_program("Normal program exit", initData);
	return (1);
}
