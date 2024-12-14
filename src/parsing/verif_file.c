#include "../../inc/utils.h"

bool	correct_file_type(char *input)
{
	int		len;
	void	*mlx;
	void	*img;
	int		size;

	size = 1000;
	if (input)
	{
		len = ft_strlen(input);
		if (input[len - 3] == '.' && input[len - 2] == 'x' \
			&& input[len - 1] == 'p' && input[len] == 'm')
		{
			mlx = mlx_init();
			img = mlx_xpm_file_to_image(mlx, input, &size, &size);
			if (img)
				return (true);
			else
				print_error(input, "File .xpm image reading has failed.");
		}
		else
			print_error(input, "File is not an .xpm format.");
		return (false);
	}
	return (false);
}

bool	verify_file(char *input)
{
	if (input)
	{
		if (correct_file_type(input))
		{
			if (good_file(input))
				return (true);
			else
				print_error(NULL, "File verification: \
				 file error");
		}
		else
			print_error(NULL, "File verification: \
			incorrect file type. Expecting .cub");
	}
	return (false);
}
