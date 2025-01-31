#include "../../inc/utils.h"

void	clean_line(char *line)
{
	if (line)
	{
		free(line);
	}
}

int	ft_lstsize_pl(t_parsed_lines *lst)
{
	int		i;
	t_parsed_lines	*next;

	if (lst == NULL)
		return (0);
	next = lst->next;
	i = 1;
	while (next != NULL)
	{
		next = next -> next;
		i++;
	}
	return (i);
}

t_parsed_lines	*ft_lstlast_pl(t_parsed_lines *lst)
{
	int	i;

	if (!lst)
		return (lst);
	i = ft_lstsize_pl(lst);
	while (i > 1)
	{
		lst = lst->next;
		i--;
	}
	return (lst);
}

int search_elements(char *line, t_game_data *initData, int pe)
{
	if (pe == 0)
	{
		// printf("initLines NULL\n");
		if (!((*initData->initLines)->line = ft_strdup(line)))
		{
			if ((*initData->initLines))
				free((*initData->initLines));
			return (0);
		}
		else if ((*initData->initLines)->line != NULL)
		{
			(*initData->initLines)->next = NULL;
			return (1);
		}
	}
	else
	{
		t_parsed_lines *new;

		new = malloc(sizeof(t_parsed_lines));
		if (!new)
			return (0);
		new->next = NULL;
		(ft_lstlast_pl((*initData->initLines)))->next = new;
		if (!((ft_lstlast_pl((*initData->initLines))->line = ft_strdup(line))))
		{
				if (initData->initLines)
					clean_elem_lines(initData->initLines);
				return (0);
		}
		else
			return (1);
	}
	return (0);
}

bool	parse_textures(int fd, t_game_data *initData, char **map_line)
{
	char	*line;
	int		parsed_elements;
	int		minimum_elements;
	t_parsed_lines	*head;

	minimum_elements = 6;
	parsed_elements = 0;
	initData->initLines = (t_parsed_lines**)malloc(sizeof(t_parsed_lines*));
	*(initData->initLines) = (t_parsed_lines*)malloc(sizeof(t_parsed_lines));
	(*initData->initLines)->next = NULL;
	(*initData->initLines)->line = NULL;
	(*initData->initLines)->id = 1;
	head = *initData->initLines;
	line = skip_empty_lines(fd);
	while (line && !is_eof(*line) && parsed_elements < minimum_elements)
	{
		parsed_elements += search_elements(line, initData, parsed_elements);
		if (line)
			free(line);
		line = skip_empty_lines(fd);
		*(initData->initLines) = head;
	}
	if (parsed_elements < minimum_elements || ft_lstsize_pl(head) < 6)
	{
		print_error("Parsing intit info", "Do not have 6 lines");
		if (line)
			free(line);
		*map_line = NULL;
		return (exit_textures(NULL));
	}
	if (line)
	{
		*map_line = ft_strdup(line);
		printf("have rem map line:%s$\n", *map_line);
		free(line);
	}
	return (true);
}
