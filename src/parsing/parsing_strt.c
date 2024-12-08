#include "../inc/parsing.h"

void	clean_line(char *line)
{
	if (line)
	{
		free(line);
	}
}

bool	parse_textures(int fd, t_game_data *initData)
{
	char	*type[] = {"NO", "SO", "WE", "EA", "F", "C"};
	char	*line;
	char	*pline; 
	int		i;

	i = 0;
	line = getnextline(fd);
	pline = &line;
	while (!is_eof(line))
	{
		skip_spaces(line);
		if (token_found(type[i], line))
		{
			save_texture(type[i], initData);
			i++;
		}
		if (i == 6)
		{
			print_message("Saved all textures");
			clean_line(pline);
			return (true);
		}
		clean_line(pline);
		line = getnextline(fd);
	}
	if (i < 6)
	{
		print_error("Parsing intit info", "Did not have all the necessary textures");
		return (false);
	}
	return (true);
}


bool	parsing(int fd)
{
	t_game_data	*initData;
	char	*line;

	initData = malloc(sizeof(t_game_data));
	if (!parse_textures(fd, initData))
	{
		//clean initData;
		return (false);
	}
	else
		printf("parsed all init data\n");
}