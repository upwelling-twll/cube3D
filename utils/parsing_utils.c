#include "../inc/parsing.h"

bool	token_found(char *search, char *input)
{
	if (search && input)
	{
		if (ft_strncmp(search, input, ft_strlen(search)))
			return(false);
		else
			return (true);
	}
	else
	{
		print_message("parsing textures. token_found: \
		no input or search");
		return (false);
	}
}

bool	save_texture(char *type, char *line, t_game_data *initData)
{
	
}

bool	exit_textures(int fd, char *line, t_game_data *initData)
{
	clean_initData(initData);
	print_error("parse_textures: found token for line:%s. Error\
	 saving token.", line);
	if (line)
		free(line);
	return (false);
}
