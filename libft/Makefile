SRCS	=	ft_atoi.c	ft_calloc.c	ft_isalpha.c	ft_isdigit.c	ft_striteri.c	\
	ft_memchr.c	ft_memcpy.c	ft_memset.c	ft_putendl_fd.c	ft_putstr_fd.c	ft_strchr.c	\
	ft_strjoin.c	ft_strlcpy.c	ft_strmapi.c	ft_strnstr.c	ft_strtrim.c	\
	ft_tolower.c ft_bzero.c	ft_isalnum.c	ft_isascii.c	ft_isprint.c	ft_itoa.c	\
	ft_memcmp.c	ft_memmove.c	ft_putchar_fd.c	ft_putnbr_fd.c	ft_split.c	ft_strdup.c	\
	ft_strlcat.c	ft_strlen.c	ft_strncmp.c	ft_strrchr.c	ft_substr.c	ft_toupper.c	\
	ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c	\
	ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c	ft_lstmap.c \
	ft_numlen.c ft_putnbr_int.c ft_putcharlen.c thex.c print_d.c print_u.c print_p.c ft_print.c ft_putstrlen.c \
	get_next_line.c get_next_line_utils.c  ft_strlen_sst.c ft_strndup.c\

NAME	=	libft.a

HEADER	=	libft.h

OBJ	=	$(SRCS:.c=.o)

CC	=	cc

CFLAGS	=	-Wall -Werror -Wextra

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	ar rcs $(NAME) $(OBJ)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)
		
re	:	fclean all

.PHONY	:	all clean fclean re