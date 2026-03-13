NAME = push_swap
CC = cc
RM = rm -f

LIBFT_DIR = utils/libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = utils/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRC = main.c parsing/parse_checking.c utils/utils.c parsing/parse_utils.c
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I. -I$(LIBFT_DIR) -I. -I$(PRINTF_DIR)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

clean :
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean : clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: re all clean fclean
