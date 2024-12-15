#include "../../inc/utils.h"

void	clean_line(char *line)
{
	if (line)
	{
		free(line);
	}
}

int search_elements(char *line, char **type, int fd, t_game_data *initData)
{
	char	**pline; 
	int		i;

	i = 0;
	skip_tab_spaces(line);
	pline = &line;
	if (token_found(type[i], line))
	{
		skip_tab_spaces(line);
		if (save_texture(type[i], line, initData))
			i++;
		else
			return(exit_textures( *pline, initData));
	}
	if (i == 6)
	{
		print_message("Checked all textures");
		clean_line(*pline);
		return (i);
	}
	clean_line(*pline);
	line = get_next_line(fd);
	pline = &line;
	return (i);
}

bool	parse_textures(int fd, t_game_data *initData)
{
	char	*type[] = {"NO", "SO", "WE", "EA", "F", "C"};
	char	*line;
	int		parsed_elements;;
	int		minimum_elements;

	minimum_elements = 6;
	line = get_next_line(fd);
	while (!is_eof(*line))
	{
		parsed_elements = search_elements(line, type, fd, initData);
	}
	if (parsed_elements < minimum_elements)
	{
		print_error("Parsing intit info", "Did not have \
		all the necessary textures");
		return (false);
	}
	return (true);
}
