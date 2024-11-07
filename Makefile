CC = gcc
FLAGS = -Werror -Wall -Wextra

NAME = push_swap.a

SOURCES = \
	src/sa.c \
	

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

test: $(NAME)
	cc test.c -o test.out
	ar rcs $(NAME) test.out
	./$(NAME)

.PHONY: all clean fclean re test