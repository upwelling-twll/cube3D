#include "../../inc/validation.h"

bool	valid_map(t_game_data **idata)
{
	if (!idata || !is_valid_map(idata, (*idata)->maplines))
	{
		return (false);
	}
	return (true);
}

int	is_valid_elem(t_parsed_lines *pline, t_game_data **idata)
{
	char	*cpline;
	char	*etype;

	etype = NULL;
	if (!pline || is_empty_line(pline->line))
		return (0);
	cpline = skip_tab_spaces(pline->line);
	if (!(is_etoken(cpline, &etype)) || !(is_unique(idata, etype)))
		return (0);
	cpline += ft_strlen(etype);
	cpline = skip_tab_spaces(cpline);
	if (ft_strlen(etype) == 2 && (correct_path(cpline))) //for WE, EA, SO,NO
	{
		if (!save_txtr(idata, cpline, etype))
			return (0);
	}
	else if (ft_strlen(etype) == 1 && (correct_colours(cpline))) //for F and C
	{
		if (!save_rgb(idata, cpline, etype))
			return (false);	
	}
	else
		return (0);
	return (1);
}

bool	valid_elements(t_game_data **idata)
{
	int				i;
	int				nelem;
	t_parsed_lines	*line;
	
	nelem = 6;
	i = 0;
	line = *(*idata)->initlines;
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
	if (!(*idata) || !((*idata)->initlines) || !((*idata)->maplines))
	{
		printf("validation:no init data or lines or map\n");
		return (false);
	}
	if (!valid_elements(idata))
	{
		printf("validation: validating elements failed\n");
		return (false);
	}
	if (!valid_map(idata))
	{
		printf("validation: validating map failed\n");
		return (false);
	}
	return (true);
}
