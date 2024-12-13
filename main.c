#include "./inc/parsing.h"
#include "./inc/utils.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (!verify_file(argv[1]))
			return(exit_program("exiting Cube3D"));
		if (!parsing(argv[1]))
			return(exit_program("exiting Cube3D"));
	}
	else
		return(exit_program("Program expects 1 parametor: example.cub"));
}
