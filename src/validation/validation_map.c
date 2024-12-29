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
			return (false);
		if (line [i] != '1' && line[i] != ' ' && line[i] != '\n')
			return (false);
		i++;
	}
	if (wall > 0)
		return (true);
	return (false);
}

bool	replace_sp_to_x(t_game_data **idata)
{
	if (idata)
		printf("function replace_sp_to_x:STUB\n");
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
		return (print_error(NULL, "Map validation: character issue"));
	printf("Validation: one and only hero exists\n");
	if (!is_wall(lmap[0]))
		return (print_error(lmap[0], "<- first map line is NOT wall"));
	printf("Validation: first map line is a wall\n");

	nmap= remove_last_nlsp(idata);
	if (!nmap)
		return (print_error(lmap[0], "map error: after removing last nlsp"));
	
	print_validated_map((*idata)->mapLines);
	lnum = get_array_size((*idata)->mapLines);

	if (!is_wall(nmap[lnum]))
		return (print_error(nmap[lnum], "<- last map line is NOT wall"));
	if (!(replace_sp_to_x(idata)))
		return (print_error(NULL, "replacing 'spaces' to 'x' error"));
	nmap = dfs_check_walls((*idata)->mapLines, 'x', 'v');
	if (!nmap)
		return (clean_map(nmap), print_error(NULL, "dfs error"));
	if (!compare_maps((*idata)->mapLines, nmap))
		return (clean_map(nmap), print_error(NULL, "compare maps error"));
	return (print_message("Validation: is_valid_map OK"), true);
}	

