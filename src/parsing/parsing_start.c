#include "../../inc/utils.h"

void	init_txtr(t_txtr *newtxt)
{
	newtxt->fd = -1;
	newtxt->path = NULL;
	newtxt->status = false;
	newtxt->type = NULL;
}

void	init_structs(t_game_data **initData)
{
	init_txtr(&(*initData)->no_path);
	init_txtr(&(*initData)->so_path);
	init_txtr(&(*initData)->we_path);
	init_txtr(&(*initData)->ea_path);
	(*initData)->floor.status = false;
	(*initData)->celling.status = false;
}

bool	parsing(char *path, t_game_data **initData)
{
	// t_game_data	*initData;
	int			fd;
	char		*map_line;

	if (!path)
		return (false);
	*initData = malloc(sizeof(t_game_data));
	init_structs(initData);
	if (!(*initData))
		return (print_error(NULL, "Parsing:can not create initData"));
	fd = open(path, O_RDONLY);
	if (parse_textures(fd, *initData, &map_line))
	{
		if (parse_map(path, fd, *initData, map_line))
		{
			close(fd);
			// print_parsed_map((*initData)->mapLines);
			return (true);
		}
		else
			printf("Parsing. saving map: did not save map\n");
	}
	else
		printf("Parsing textures: did not parse textures\n");
	close(fd);
	if (map_line)
	{
		printf("map line\n");
		printf("cleaning remaining map line^%s\n", map_line);
		free(map_line);
	}
	printf("exiting parsing\n");
	return (false);
}

