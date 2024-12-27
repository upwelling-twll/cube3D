#include "../../inc/validation.h"

bool	has_one_hero(char **lmap)
{
	if (lmap)
		printf("function has_one_character:STUB\n");
	return (true);
}

bool	is_wall(char *line)
{
	if (line)
		printf("function is_wall:STUB\n");
	return (true);
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
	return (true);
}

bool	is_valid_map(t_game_data **idata, char **lmap)
{
	int		lnum;
	char	**nmap;

	if (!(has_one_hero(lmap)))
		return (print_error(NULL, "Map validation: character issue"));
	if (!is_wall(lmap[0]))
		return (print_error(lmap[0], "<- first map line is NOT wall"));
	(*idata)->mapLines = remove_last_nlsp(idata);
	if (!((*idata)->mapLines))
		return (print_error(lmap[0], "there is no map after removing last nlsp"));
	lnum = get_array_size((*idata)->mapLines);
	if (!is_wall(lmap[lnum]))
		return (print_error(lmap[0], "<- last map line is NOT wall"));
	if (!(replace_sp_to_x(idata)))
		return (print_error(NULL, "replacing 'spaces' to 'x' error"));
	nmap = dfs_check_walls((*idata)->mapLines, 'x', 'v');
	if (!nmap)
		return (clean_map(&nmap), print_error(NULL, "dfs error"));
	if (!compare_maps((*idata)->mapLines, nmap))
		return (clean_map(&nmap), print_error(NULL, "compare maps error"));
	return (print_message("Validation: is_valid_map OK"), true);
}	

