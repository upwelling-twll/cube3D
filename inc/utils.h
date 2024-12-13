#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

//drop_message.c
void	print_message(char *text);
void	print_error(char *data, char *text);

//exit_program.c
int		exit_program(char *text);

//skip_tab_spaces.c
bool	is_eof(char c);
bool	is_tab_or_space(char c);
bool	is_tab_or_space(char c);
void	skip_tab_spaces(char *line);