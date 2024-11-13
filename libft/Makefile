CC = gcc
FLAGS = -Werror -Wall -Wextra

NAME = libft.a

SOURCES = \
	char/ft_putchar_fd.c \
	char/ft_putchar.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	str/ft_substr.c \
	str/ft_strncmp.c \
	str/ft_strnstr.c \
	str/ft_strrchr.c \
	str/ft_strlcpy.c \
	str/ft_strlen.c \
	str/ft_strmapi.c \
	str/ft_striteri.c \
	str/ft_strjoin.c \
	str/ft_strlcat.c \
	str/ft_split.c \
	str/ft_putstr.c \
	str/ft_putstr_fd.c \
	str/ft_strdup.c \
	str/ft_strtrim.c \
	str/ft_strchr.c \
	str/ft_putendl_fd.c \
	str/ft_calloc.c \
	to/ft_toupper.c \
	to/ft_tolower.c \
	to/ft_atoi.c \
	to/ft_itoa.c \
	to/ft_itoa_base.c \
	nbr/ft_putnbr.c \
	nbr/ft_putnbr_base.c \
	nbr/ft_putnbr_fd.c \
	nbr/ft_nbrlen.c \
	is/ft_isalnum.c \
	is/ft_isalpha.c \
	is/ft_isascii.c \
	is/ft_isdigit.c \
	is/ft_isprint.c \
	mem/ft_memcmp.c \
	mem/ft_memcpy.c \
	mem/ft_memmove.c \
	mem/ft_memchr.c \
	mem/ft_memset.c \
	mem/ft_bzero.c \
	lst/ft_lstiter.c \
	lst/ft_lstlast.c \
	lst/ft_lstmap.c \
	lst/ft_lstadd_front.c \
	lst/ft_lstclear.c \
	lst/ft_lstdelone.c \
	lst/ft_lstnew.c \
	lst/ft_lstadd_back.c \
	lst/ft_lstsize.c \
	print/main.c \
	print/prints/print_c.c \
	print/prints/print_i.c \
	print/prints/print_p.c \
	print/prints/print_s.c \
	print/prints/print_u.c \
	print/prints/print_x.c

OBJ_DIR = objects
OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	$(CC) $(FLAGS) -c $< -I . -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
