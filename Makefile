
.PHONY: all clean fclean re

NAME = lem-in
NAME_LIBFT = libft.a

LIBFT = $(addprefix $(LIBFT_DIR),$(NAME_LIBFT))

SRC_DIR = ./src/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/
LFT = -L $(LIBFT_DIR) -lft

SRCS_LIST = main.c find_way.c answer_ants_run.c destroyers.c get_ants.c get_data.c get_links.c \
get_rooms.c init_data.c store_input_strings.c queue.c
HEADERS_LIST = lemin.h

SRCS = $(addprefix $(SRC_DIR),$(SRCS_LIST))

OBJS = $(SRCS:.c=.o)

INCLUDES = -I $(INC_DIR) -I $(LIBFT_DIR)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

%.o: %.c $(addprefix $(INC_DIR),$(HEADERS_LIST))
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
	@echo ".\c"

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(LFT) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "$(NAME_PS) executable created"

# $(NAME_CH): $(LIBFT) $(OP_OBJS) $(CH_OBJS)
# 	@$(CC) $(CFLAGS) $(LFT) $(INCLUDES) $(OP_OBJS) $(CH_OBJS) -o $(NAME_CH)
# 	@echo "$(NAME_CH) executable created"

FORCE: ;

$(LIBFT): FORCE
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