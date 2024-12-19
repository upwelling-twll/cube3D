#include "./inc/utils.h"

int	main(int argc, char *argv[])
{
	t_game_data	*initData;

	if (argc == 2)
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
}
