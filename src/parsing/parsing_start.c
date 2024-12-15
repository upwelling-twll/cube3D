#include "../../inc/utils.h"

bool	parsing(char *path)
{
	t_game_data	*initData;
	int			fd;

	initData = malloc(sizeof(t_game_data));
	if (!initData)
		return (print_error(NULL, "Parsing:can not create initData"));
	fd = open(path, O_RDONLY);
	if (parse_textures(fd, initData))
	{
		printf("Parsing textures:parsed all init data\n");
		if (parse_map(path, fd, initData))
		{
			close(fd);
			return (true);
		}
		else
			printf("Parsing. saving map: did not save map\n");
	}
	else //initData cleaned in parse_texture function exit_textures;
		printf("Parsing textures: did not pars textures\n");
	close(fd);
	return (false);
}
