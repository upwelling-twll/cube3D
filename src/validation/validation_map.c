#include "../../inc/validation.h"

bool	is_valid_map(t_game_data **idata, char **lmap)
{
	int	lnum;

	if (!is_wall(lmap[0]))
		return (print_error(lmap[0], "<- first map line is NOT wall"));
	(*idata)->mapLines = remove_backward_nlsp(idata);
	if (!((*idata)->mapLines))
		return (print_error(lmap[0], "there is no map after removing nlsp in the end"));
	lnum = get_arrey_size((*idata)->mapLines);
	if (!is_wall(lmap[lnum]))
		return (print_error(lmap[0], "<- last map line is NOT wall"));
	
}	

