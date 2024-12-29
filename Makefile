UNAME_S = $(shell uname -s)

NAME = cub3D

CC = cc

RM = rm -f

SRC = main.c ./src/parsing/parsing_start.c ./src/parsing/proc_space.c  \
	./src/parsing/verif_elements.c ./src/parsing/verif_file.c \
	./utils/drop_message.c ./utils/exit_program.c ./utils/skip_tab_spaces.c \
	./utils/parsing_dbg.c ./utils/validation_dbg.c\
	./utils/parsing_utils.c ./src/parsing/parse_textures.c ./src/parsing/parse_map.c  \
	./utils/validation_elem_utils.c	./utils/validation_map_utils.c	\
	./src/validation/validation_start.c	./src/validation/validation_elem.c	 \
	./src/validation/validation_map.c ./src/validation/validation_dfs.c\

#./src/parsing/verif_map.c  
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -O3 -g

LIBFT:= libft/libft.a

LIBS :=
ifeq ($(UNAME_S),Darwin) # MacOS
    FLAGS += -Imlx
    LIBS +=  -Lmlx -lmlx -framework OpenGL -framework AppKit

else ifeq ($(UNAME_S),Linux) # Linux
    FLAGS += -I/usr/include -Imlx_linux
    LIBS += -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
endif

%.o: %.c
	 $(CC) $(FLAGS) -Imlx -c $< -o $@ 
#>/dev/null

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@ $(CC) $(OBJ) $(LIBS) -o $(NAME) $(LIBFT)
#-fsanitize=address -g3
$(LIBFT):
	@ make -C libft/ >/dev/null

clean: 
	@ $(RM) $(OBJ)
	@ make -C libft/ clean >/dev/null

fclean: clean
	@ $(RM) $(NAME)
	@ make -C libft/ fclean >/dev/null

re: fclean all

.PHONY: all libft clean fclean re