#include "../../inc/validation.h"

bool	has_one_hero(char **lmap)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 0;
	j = 0;
	if (!lmap)
		return (false);	
	while (lmap[i])
	{
		j = 0;
		while (lmap[i][j])
		{
			if (is_hero(lmap[i][j]))
				n++;
			j++;
		}
		i++;
	}
	if (n == 1)
		return (true);
	return (false);
}

bool	is_wall(char *line)
{
	int	i;
	int	wall;

	i = 0;
	wall = 0;
	if (!line)
		return (false);
	while (line[i])
	{
		if (line[i] == '1')
			wall++;
		if (line[i] == '\n' && wall == 0)
			return (print_message("last map line is NOT wall"),false);
		if (line [i] != '1' && line[i] != ' ' && line[i] != '\n')
			return (print_message("last map line is NOT wall"),false);
		i++;
	}
	if (wall > 0)
		return (true);
	return (print_message("last map line is NOT wall"), false);
}

bool	replace_sp_to_x(t_game_data **idata, int rows)
{
	char	**nmap;
	char	**map;
	int		*rows_len;
	int		max_len;

	max_len = 0;
	map = (*idata)->mapLines;
	if (!idata || !(*idata)->mapLines)
		return (false);
	max_len = get_maxlen(map, &rows_len, rows);
	if (!max_len)
		return (false);
	// printf("max len = %i\n", max_len);
	(*idata)->map_height = rows;
	(*idata)->map_widht = max_len;
	nmap = replace_spaces(map, max_len, rows);
	if (!nmap)
		return (false);
	 print_validation_map(nmap, "Replaced sp to 'x'");
	// clean_map((*idata)->mapLines);
	(*idata)->mapLines = nmap;
	return (true);
}

bool	compare_maps(char **spmap, char **vmap)
{
	if (spmap)
		printf("function compare_maps:STUB\n");
	if (!vmap)
		return (true);
	return (true);
}

bool	is_valid_map(t_game_data **idata, char **lmap)
{
	int		lnum;
	char	**nmap;

	nmap = NULL;
	lnum = 0;
	if (!(has_one_hero(lmap)))
		return (print_message("Map validation: character issue"), false);
	printf("Validation: one and only hero exists\n");
	if (!is_wall(lmap[0]))
		return (print_message("first map line is NOT wall"), false);
	printf("Validation: first map line is a wall\n");
	nmap= remove_last_nlsp(idata);
	if (!nmap)
		return (print_message("map error: after removing last nlsp"), false);
	// print_validation_map((*idata)->mapLines, "Removed exptra nlsp");
	lnum = get_array_size((*idata)->mapLines);
	if (!is_wall(nmap[lnum]) ) // || !has_internal_walls(nmap)
		return (print_message("walls check failed"), false);
	if (!(replace_sp_to_x(idata, lnum)))
		return (print_message("replacing 'spaces' to 'x' error"), false);
	if  (!check_walls((*idata)->mapLines, (*idata)->map_height, (*idata)->map_widht))
		return (print_message("Spaces check failed"), false);
	// if (!compare_maps((*idata)->mapLines, nmap))
	// 	return (clean_map(nmap), print_error(NULL, "compare maps error"));
	return (print_message("Validation: is_valid_map OK"), true);
}	

