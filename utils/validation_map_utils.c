#include "../inc/validation.h"

char	**remove_last_nlsp(t_game_data **idata)
{
	if (idata)
		printf("function remove_last_nlsp:STUB\n");
	return ((*idata)->mapLines);
}

int	get_array_size(char **array)
{
	if (array)
		printf("function get_array_size:STUB\n");
	return (100);
}

void	clean_map(char ***map)
{
	if (map)
		printf("function clean_map:STUB\n");
	return ;
}

bool	is_hero(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	else
		return (false);
}
