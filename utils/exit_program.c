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

int exit_program(char *text)
{
	if (text)
		printf("%s\n", text);
	return (1);
}
