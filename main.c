#include "./inc/validation.h"

int	main(int argc, char *argv[])
{
	t_game_data	*initData;

	// argv[1] = "file.cub";
	if (argc == 2) //replace to argc == 2
	{
		if (!verify_file(argv[1]))
			return(exit_program("exiting Cube3D"));
		if (!(parsing(argv[1], &initData)))
			return(exit_program("exiting Cube3D"));
		if (!validation(&initData))
			return(exit_program("exiting Cube3D"));
	}
	else
		return(exit_program("Program expects 1 parametor: example.cub"));
	clean_elem_lines(initData->initLines);
	// clean_map(initData->mapLines);
	exit_program("Program exit");
}
