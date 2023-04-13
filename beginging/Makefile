NAME = push_swap
SRC = main.c lists.c checknum.c instructions.c

OBJ = $(SRC:.c=.o)
#-fsanitize=address
FLAGS = -Wall -Wextra -Werror

LIB = ../libft

all: ${NAME}

${NAME}: ${OBJ}
		make -C $(LIB)
		@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB)/libft.a

$(OBJ): $(SRC)
		@gcc $(FLAGS) -c $(SRC)

#COMPILE WITH ARGUMENTS
exe: all
		@./$(NAME) 1 2 3 4 5

clean:
		@rm -rf $(OBJ)
		@make -C $(LIB) clean

fclean: clean
		@rm -rf $(NAME)
		@make -C $(LIB) fclean

re: fclean all

.PHONY: clean fclean all re
