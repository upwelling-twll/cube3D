#include "../../inc/utils.h"

bool	correct_path(char *line)
{
	if (!line || is_eof(line) || is_empty_line(line))
		return (false);
	if (verify_file_xpm(line))
		return (true);
	return (false);
}

bool	correct_colour(char *line)
{
	int	i;
	int	code;

	i = 0;
	code = -1;
	if (!line || is_eof(line) || is_empty_line(line))
		return (false);
	while (i < 3)
	{
		code = ft_atoi(line);
		if (code >= 0 && code <= 255)
		{
			
		}
	}
}

bool	save_txtr(idata, path)
{

}

bool	save_rgb(idata, path)
{

}

bool	is_unique(t_game_data **d, char *t)
{
	if (!ft_strncmp(t, "NO", 2) && (*d)->no_path.status == true)
		return (false);
	else if (!ft_strncmp(t, "SO", 2) && (*d)->so_path.status == true)
		return (false);
	else if (!ft_strncmp(t, "WE", 2) && (*d)->we_path.status == true)
		return (false);
	else if (!ft_strncmp(t, "EA", 2) && (*d)->ea_path.status == true)
		return (false);
	else if (!ft_strncmp(t, "F", 2) && (*d)->floor.status == true)
		return (false);
	else if (!ft_strncmp(t, "C", 2) && (*d)->celling.status == true)
		return (false);
	else
		return (true);
}

bool	is_etoken(char *cpline, char **etype)
{
	char	*types[6];
	int		etlen;

	types[0] = "NO";
    types[1] = "SO";
    types[2] = "WE";
    types[3] = "EA";
    types[4] = "F";
    types[5] = "C";
	etlen = 0;
	if (!cpline || is_eof(cpline) || is_empty_line(cpline))
		return (false);
	etlen = is_etoken_len(cpline);
	if (etlen == 2)
		*etype = is_texture(cpline, types); 
	else if (etlen == 1)
		*etype = is_rgb(cpline, types);
	if (!(*etype))
		return (false);
	return (true);
}