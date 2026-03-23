NAME = push_swap
CC = cc
RM = rm -rf

OBJ_DIR = obj
LIBFT_DIR = utils/libft
PRINTF_DIR = utils/ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRC = main.c\
	  push_swap.c\
	  parsing/parse_checking.c\
	  parsing/parse_utils.c\
	  utils/utils.c\
	  utils/free_obj.c\
	  utils/print_bench.c\
	  operations/push.c\
	  operations/rotation.c\
	  operations/swap.c\
	  operations/reverse_rotation.c\
	  algorithme/simple.c\
	  algorithme/complex.c\
	  algorithme/complex_utils.c\
	  algorithme/adaptative.c\
	  algorithme/fewer_args.c\
	  algorithme/algo_utils.c\
	  algorithme/preparation.c\
	  algorithme/medium.c\

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

CFLAGS = -Wall -Werror -Wextra -I. -I$(LIBFT_DIR) -I. -I$(PRINTF_DIR)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

clean :
	$(RM) $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean : clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: re all clean fclean
