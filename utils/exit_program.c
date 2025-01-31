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

bool	exit_textures(char *line)
{
	if (line)
		free(line);
	return (false);
}

void	clean_textures(t_game_data *data)
{
	if (data->no_path.status == true)
	{
		free(data->no_path.type);
		free(data->no_path.path);
	}
	if (data->so_path.status == true)
	{
		free(data->so_path.type);
		free(data->so_path.path);
	}
	if (data->we_path.status == true)
	{
		free(data->we_path.type);
		free(data->we_path.path);
	}
	if (data->ea_path.status == true)
	{
		free(data->ea_path.type);
		free(data->ea_path.path);
	}
}

int exit_program(char *text, t_game_data *initData)
{
	printf("exit program\n");
	if (text)
		printf("%s\n", text);
	if (initData && initData->initLines)
		clean_elem_lines(initData->initLines);
	if (initData && initData->mapLines)
		clean_map(initData->mapLines);
	if (initData)
		clean_textures(initData);
	if (initData)
		free(initData);
	return (1);
}
