NAME             = push_swap
BONUS            = checker
CC                 = gcc
FLAGS            = -Wall -Wextra -Werror
RM                 = rm -rf

SRC_PATH         = src/
SRCS = main.c swap.c rotate.c reverse_rotate.c push.c \
		content.c get.c cost.c sort.c sort_2.c parse.c

BONUS_SRCS = bonus/main.c \
		src/swap.c src/push.c src/rotate.c src/reverse_rotate.c \
		src/parse.c

HEADER_PATH     = includes/
HEADERS            = push_swap.h

INCLUDES    = $(patsubst %.h, $(HEADER_PATH)%.h, $(HEADERS))

OBJS_DIR        =  .objects/
OBJS            =  $(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))
BONUS_OBJS            =  $(patsubst %.c, %.o, $(BONUS_SRCS))

LIBFT_DIR = libft
LIBFT_MAKEFILE = $(LIBDIR)/Makefile
LIBFT = libft.a

all: $(NAME)

$(NAME): $(OBJS) Makefile $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(FLAGS) -I $(HEADER_PATH) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(BONUS): $(BONUS_OBJS) Makefile $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(FLAGS) -I $(HEADER_PATH) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -o $(BONUS)

$(LIBFT_DIR)/$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)%.o :  $(SRC_PATH)%.c $(SRC_PATH)%.c $(INCLUDES)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -I $(HEADER_PATH) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test