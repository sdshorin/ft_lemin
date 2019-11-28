
.PHONY: all clean fclean re

NAME = lem-in
NAME_LIBFT = libft.a

LIBFT = $(addprefix $(LIBFT_DIR),$(NAME_LIBFT))

SRC_DIR = ./src/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/
LFT = -L $(LIBFT_DIR) -lft

SRCS_LIST = main.c destroyers.c get_ants.c get_data.c get_links.c \
	get_rooms.c init_data.c store_input_strings.c queue.c 	algo_find_new_way.c \
	algo_find_way.c algo_make_new_way.c algo_recipe.c output_ants.c \
	output_ants_run.c output_path_sort.c
	HEADERS_LIST = lemin.h

SRCS = $(addprefix $(SRC_DIR),$(SRCS_LIST))

OBJS = $(SRCS:.c=.o)

INCLUDES = -I $(INC_DIR) -I $(LIBFT_DIR)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(addprefix $(INC_DIR),$(HEADERS_LIST))
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
	@echo ".\c"

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(LFT) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "$(NAME_PS) executable created"

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@/bin/rm -f $(OBJS) $(OBJS) $(OBJS)
	@echo "Object files deleted"
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Executable files deleted"
	@make fclean -C $(LIBFT_DIR)

re: fclean all
