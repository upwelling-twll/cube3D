#include "../inc/utils.h"

bool	token_found(char *search, char *input)
{
	if (search && input)
	{
		if (ft_strncmp(search, input, ft_strlen(search)))
			return(false);
		else
			return (true);
	}
	else
	{
		print_message("parsing textures. token_found: \
		no input or search");
		return (false);
	}
}

void	move_line(int value, char **line)
{
	if (value > 0 && value < 10)
		*line = *(line + 1);
	else if (value > 10 && value < 100)
		*line = *(line + 2);
	else if (value > 100 && value <= 255)
		*line = *(line + 3);
}

// void	save_rgb(t_rgb *colours, int value, int i)
// {
// 	if (i == 0)
// 		colours->red = value;
// 	else if (i == 1)
// 		colours->green = value;
// 	else if (i == 2)
// 		colours->blue = value;
// }

// bool	saved_colour(char *line, t_game_data *InitData, char *type)
// {
// 	int		i;
// 	int		value;
// 	t_rgb	*colours;

// 	i = 0;
// 	colours = maaaaalloc(sizeof(t_rgb));
// 	while (*line != '\0' || *line != '\n')
// 	{
// 		skip_tab_spaces(line);
// 		value = ft_atoi(line);
// 		if (value < 0 || value > 255)
// 			break;
// 		move_line(value, &line);
// 		save_rgb(colours, value, i);
// 		i++;
// 	}
// 	if (i != 3)
// 	{
// 		free(colours);
// 		return (false);
// 	}
// 	if (!ft_strncmp(type, "F", 1))
// 		InitData->floor = colours;
// 	else
// 		InitData->celling = colours;
// 	return (true);
// }

// bool	save_texture(char *type, char *line, t_game_data *initData)
// {
// 	if (ft_strncmp(type, "NO", 2) == 0)
// 		initData->no_path = line;
// 	else if (ft_strncmp(type, "SO", 2) == 0)
// 		initData->so_path = line;
// 	else if (ft_strncmp(type, "WE", 2) == 0)
// 		initData->we_path = line;
// 	else if (ft_strncmp(type, "EA", 2) == 0)
// 		initData->ea_path = line;
// 	else if (ft_strncmp(type, "F", 1) == 0)
// 	{
// 		if (!saved_colour(line, initData, "F"))
// 			return (false);
// 	}
// 	else if (ft_strncmp(type, "C", 1) == 0)
// 	{
// 		if (!saved_colour(line, initData, "C"))
// 			return (false);
// 	}
// 	return (true);
// }


void	clean_initData(t_game_data *initData)
{
	if (!initData)
		return ;
	// if (initData->floor)
	// 	free(initData->floor);
	// if (initData->celling)
	// 	free(initData->celling);
	free(initData);
	printf("cleaned initData");
}

bool	is_empty_line(char *line)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!line)
		return (false);
	len = ft_strlen(line);
	while (i < len && (line[i] == ' ' || line[i] == '\n' || line[i] == '\t'))
		i++;
	if (line[i] == '\0')
		return(true);
	else
		return (false);
}

char	*skip_empty_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
	{
		while (is_empty_line(line) == true)
		{
			printf("had empty line:%s$\n", line);
			if (line)
				free(line);
			line = get_next_line(fd);
		}
		if (line)
			return (line);
	}
	return (NULL);
}

bool	exit_textures(char *line, t_game_data *initData)
{
	clean_initData(initData);
	print_error("parse_textures: found token for line:%s. Error\
	 saving token.", line);
	if (line)
		free(line);
	return (false);
}
