#include "../../inc/utils.h"

bool	valid_map(t_game_data **idata)
{
	if (*idata)
		return (true);
	return (false);
}

int	is_valid_elem(t_parsed_lines *pline, t_game_data **idata)
{
	char	*cpline;
	char	*etype;

	etype = NULL;
	printf("\nis_valid_elem\n pline->line:%s$", pline->line);	
	if (!pline || is_empty_line(pline->line))
		return (0);
	printf("pline->line:%s$", pline->line);
	cpline = skip_tab_spaces(pline->line);
	if (!(is_etoken(&cpline, &etype)) || !(is_unique(idata, etype)))
		return (0);
	cpline += ft_strlen(etype);
	cpline = skip_tab_spaces(cpline);
	if (ft_strlen(etype) == 2 && (correct_path(cpline)))
		save_txtr(idata, cpline);
	else if (ft_strlen(etype) == 1 && (correct_colour(cpline)))
		save_rgb(idata, cpline);
	else
		return (0);
	printf("cpline:%s$", cpline);
	return (1);
}

bool	valid_elements(t_game_data **idata)
{
	int				i;
	int				nelem;
	t_parsed_lines	*line;
	
	nelem = 6;
	i = 0;
	line = *(*idata)->initLines;
	while (line)
	{
		i += is_valid_elem(line, idata);
		line = line->next;
	}
	if (i != nelem)
		return (false);
	return (true);
}

bool	validation(t_game_data **idata)
{
	if (!(*idata) || !((*idata)->initLines) || !((*idata)->mapLines))
	{
		printf("validation:no init data or lines or map\n");
		return (false);
	}
	if (!valid_elements(idata))
	{
		printf("validation: validating elements failed\n");
		return (false);
	}
	printf("	~All elements are valid~\n");
	if (!valid_map(idata))
	{
		printf("validation: validating map failed\n");
		return (false);
	}
	return (true);
}