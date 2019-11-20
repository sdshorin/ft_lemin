
.PHONY: all clean fclean re

NAME = lem-in
NAME_LIBFT = libft.a

LIBFT = $(addprefix $(LIBFT_DIR),$(NAME_LIBFT))

SRC_DIR = ./src/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/
LFT = -L $(LIBFT_DIR) -lft

SRCS_LIST = main.c
HEADERS_LIST = lem-in.h

SRCS = $(addprefix $(SRC_DIR),$(SRCS_LIST))

OBJS = $(SRCS:.c=.o)

INCLUDES = -I $(INC_DIR) -I $(LIBFT_DIR)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_PS) $(NAME_CH)

%.o: %.c $(addprefix $(INC_DIR),$(HEADERS_LIST))
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
	@echo ".\c"

$(NAME_PS): $(LIBFT) $(OP_OBJS) $(PS_OBJS)
	@$(CC) $(CFLAGS) $(LFT) $(INCLUDES) $(OP_OBJS) $(PS_OBJS) -o $(NAME_PS)
	@echo "$(NAME_PS) executable created"

$(NAME_CH): $(LIBFT) $(OP_OBJS) $(CH_OBJS)
	@$(CC) $(CFLAGS) $(LFT) $(INCLUDES) $(OP_OBJS) $(CH_OBJS) -o $(NAME_CH)
	@echo "$(NAME_CH) executable created"

FORCE: ;

$(LIBFT): FORCE
	@make -C $(LIBFT_DIR)

clean:
	@/bin/rm -f $(OP_OBJS) $(CH_OBJS) $(PS_OBJS)
	@echo "Object files deleted"
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@/bin/rm -f $(NAME_CH) $(NAME_PS)
	@echo "Executable files deleted"
	@make fclean -C $(LIBFT_DIR)

re: fclean all