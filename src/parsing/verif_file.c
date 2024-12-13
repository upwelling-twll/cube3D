#include "../inc/parsing.h"

bool	verify_file(char *input)
{
	if (input)
	{
		if (correct_file_type(input))
		{
			if (good_file(input))
				return (true);
			else
				print_error("File verification: \
				 file error");
		}
		else
			print_error("File verification: \
			incorrect file type. Expecting .cub");
	}
	return (false);
}
