
SRC = *.c ./builtins/*.c
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all:
	@make -C ./libft
	gcc -o minishell $(SRC) ./libft/libft.a

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ./minishell
re: fclean all