NAME	= push_swap
CC		= cc -g -Wall -Wextra -Werror
SRC		= $(wildcard src/*.c)
OBJ		= $(SRC:.c=.o)
HEADER	= libft/include/libft.h include/push_swap.h
IFLAG	= -I./include
LIBFT	= libft/libft.a

all: $(NAME) $(LIBFT)

$(LIBFT):
	@make -C libft/ all

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(OBJ) $(LIBFT) $(IFLAG) -o $(NAME)

%.o: %.c $(HEADER)
	@$(CC) -c $< -o $@ $(IFLAG)

clean:
	@make -C ./libft clean
	@rm -f src/*.o
	@rm -f *.o

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)

re: fclean all

arg:
	set arg (shuf -i 1-100 -n 100 | tr '\n' ' ')

negative:
	negative=$(shuf -i 1-100 -n 100|awk '{print $1 - 50}' | tr '\n' ' ')

.PHONY: all push_swap clean fclean re libft arg negative
