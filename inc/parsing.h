#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>

typedef	struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}		t_rgb;


typedef struct s_game_data
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;

	t_rgb	floor;
	t_rgb	celling;
} 		t_game_data;

