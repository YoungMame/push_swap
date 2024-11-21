NAME             = push_swap
BONUS            = checker
CC               = gcc
FLAGS            = -Wall -Wextra -Werror
RM               = rm -rf

SRC_PATH         = src/
SRCS             = main.c swap.c rotate.c reverse_rotate.c push.c \
                    content.c get.c cost.c sort.c sort_2.c parse.c
BONUS_PATH       = bonus/
BONUS_SRCS       = main.c parse.c content.c \
                    swap.c push.c rotate.c reverse_rotate.c

HEADER_PATH      = includes/
HEADERS          = push_swap.h

INCLUDES         = $(patsubst %.h, $(HEADER_PATH)%.h, $(HEADERS))

OBJS_DIR         = .objects/src/
OBJS             = $(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))

BONUS_OBJS_DIR   = .objects/bonus/
BONUS_OBJS       = $(patsubst %.c, $(BONUS_OBJS_DIR)%.o, $(BONUS_SRCS))

LIBFT_DIR        = libft
LIBFT            = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) -I $(HEADER_PATH) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(BONUS_OBJS) $(LIBFT)
	$(CC) $(FLAGS) -I $(HEADER_PATH) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -o $(BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)%.o : $(SRC_PATH)%.c $(INCLUDES)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -I $(HEADER_PATH) -c $< -o $@

$(BONUS_OBJS_DIR)%.o : $(BONUS_PATH)%.c $(INCLUDES)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -I $(HEADER_PATH) -c $< -o $@

clean:
	$(RM) $(BONUS_OBJS_DIR)
	$(RM) $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
