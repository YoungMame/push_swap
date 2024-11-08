NAME             = push_swap
CC                 = gcc
FLAGS            = -Wall -Wextra -Werror
RM                 = rm -rf

SRC_PATH         = src/
SRCS = main.c rules/swap.c rules/push.c rules/rotate.c rules/reverse_rotate.c \
	lst/ft_lstadd_front.c lst/ft_lstadd_back.c lst/ft_lstclear.c \
	lst/ft_lstdelone.c lst/ft_lstiter.c lst/ft_lstlast.c \
	lst/ft_lstmap.c lst/ft_lstnew.c lst/ft_lstsize.c

HEADER_PATH     = includes/
HEADERS            = push_swap.h

INCLUDES    = $(patsubst %.h, $(HEADER_PATH)%.h, $(HEADERS))

OBJS_DIR        =  .objects/
OBJS            =  $(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(FLAGS) -I $(HEADER_PATH) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o : $(SRC_PATH)%.c $(INCLUDES)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -I $(HEADER_PATH) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test