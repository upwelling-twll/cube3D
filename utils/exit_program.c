#include "../inc/utils.h"

void	clean_elem_lines(t_parsed_lines **initLines)
{
	t_parsed_lines *tmp;

	if ((!initLines) || !(*initLines))
		return ;
	tmp = (*initLines)->next;
	while ((*initLines) != NULL)
	{
		free((*initLines)->line);
		tmp =  (*initLines)->next;
		free((*initLines));
		(*initLines) = tmp;
	}
	free (initLines);
	initLines = NULL;
}

int exit_program(char *text, t_game_data *initData)
{
	if (text)
		printf("%s\n", text);
	if (initData && initData->initLines)
		clean_elem_lines(initData->initLines);
	if (initData && initData->mapLines)
		clean_map(initData->mapLines);
	if (initData)
		free(initData);
	return (1);
}
