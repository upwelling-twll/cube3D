#include "../inc/validation.h"

bool	is_comma(char c)
{
	if (c == ',')
		return (true);
	else
		return (false);
}

char*	skip_comma(char *line)
{
	if (!(is_end_of_line(*line)))
	{
		line++;
	}
	return (line);
}

char*	skip_digits(char *line)
{
	if (!is_end_of_line(*line))
	{
		while (*line && ft_isdigit(*line))
			line++;
	}
	return (line);
}

bool	save_txt_data(t_txtr *elem, char *path, char *type)
{
	char	*cptype;

	elem->status = true;
	elem->fd = -1;
	elem->path = path;
	cptype = ft_strdup(type);
	if (!cptype)
		return (false);
	elem->type = cptype;
	return (true);
}

int	is_etoken_len(char *line)
{
	int	i;
	
	i = 0;
	line = skip_tab_spaces(line);
	while (!(is_tab_or_space(line[i])))
		i++;
	return (i);
}

char	*is_texture(char *line, char **types)
{
	line = skip_tab_spaces(line);
	if (line[0] == 'N' && line[1] == 'O' && is_tab_or_space(line[2]))
		return (types[0]);
	if (line[0] == 'S' && line[1] == 'O' && is_tab_or_space(line[2]))
		return (types[1]);
	if (line[0] == 'W' && line[1] == 'E' && is_tab_or_space(line[2]))
		return (types[2]);
	if (line[0] == 'E' && line[1] == 'A' && is_tab_or_space(line[2]))
		return (types[3]);
	return (NULL);
}

char	*is_rgb(char *line, char **types)
{
	line = skip_tab_spaces(line);
	if (line[0] == 'F' && is_tab_or_space(line[1]))
		return (types[4]);
	if (line[0] == 'C' && is_tab_or_space(line[1]))
		return (types[5]);
	return (NULL);
}
