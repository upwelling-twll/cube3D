#include "../../inc/utils.h"

bool	verify_file_xpm(char *input)
{
	int		len;
	// void	*mlx;
	// void	*img;
	int		size;

	size = 1000;
	len = ft_strlen(input);
	if (len > 4 && (input[len - 4] == '.' && input[len - 3] == 'x' \
			&& input[len - 2] == 'p' && input[len - 1] == 'm'))
	{
		// mlx = mlx_init();
		// img = mlx_xpm_file_to_image(mlx, input, &size, &size);
		// if (img)
			return (true);
		// else
		// 	print_error(input, "File .xpm image reading has failed.");
	}
	else
		print_error(input, "File is not .xpm format.");
	return (false);
}

bool 	verify_file_cub(char *input)
{
	size_t	len;

	len = ft_strlen(input);
	if (len >= 4 && (input[len - 4] == '.' && input[len - 3] == 'c' \
			&& input[len - 2] == 'u' && input[len - 1] == 'b'))
	{
		return (true);
	}
	else
		print_error(input, "File is not .cub format.");
	return (false);
}

bool	correct_file_type(char *input, char *type)
{
	if (input)
	{
		if (ft_strncmp(".cub", type, 4) == 0)
			return (verify_file_cub(input));
		else if (ft_strncmp(".xpm", type, 4) == 0)
			return (verify_file_xpm(input));
	}
	return (false);
}

bool	verify_file(char *input)
{
	if (input)
	{
		if (correct_file_type(input, ".cub"))
		{
			if (good_file(input))
			{
				print_message("File is successfully verified");
				return (true);
			}
			else
				print_error(NULL, "File verification: open file error");
		}
		else
			print_error(NULL, "File verification: incorrect file type. Expecting .cub");
	}
	return (false);
}
