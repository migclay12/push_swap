NAME = push_swap
SRC = beginging/main.c beginging/lists.c beginging/checknum.c beginging/instructions.c \
		beginging/instructions_a.c beginging/instructions_b.c beginging/instructions_ab.c \
		beginging/test.c beginging/radix.c

OBJ = $(SRC:.c=.o)
#-fsanitize=address
FLAGS = -Wall -Wextra -Werror -fsanitize=address

LIB = libft

all: ${NAME}

${NAME}: ${OBJ}
		make -C $(LIB)
		@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB)/libft.a

#$(OBJ): $(SRC)
#		@gcc $(FLAGS) -c $(SRC)

#COMPILE WITH ARGUMENTS
exe: all
		@./$(NAME) 3
#5 3 4 2 1
#2 4 3 1 5
#2 4 3 5 1
#3 5 4 2 1

clean:
		@rm -rf $(OBJ)
		@make -C $(LIB) clean

fclean: clean
		@rm -rf $(NAME)
		@make -C $(LIB) fclean

comp: fclean exe

re: fclean all

.PHONY: clean fclean all re


#Invalid Characters
#[1 2a 3                   ]        KO        KO	???
#[a 1 2 3                  ]        KO        KO	???
#[1 2 3 a                  ]        KO        KO	???
#[- 1 2 3                  ]        KO        KO	???
#[+ 1 2 3                  ]        KO        KO	???

#Over INT_MAX/INT_MIN
#[2147483648 2 1           ]        KO        KO	
#[-2147483649 2 1          ]        KO        KO	

#Over LONG_MAX/LONG_MIN
#[+9223372036854775808 2 1 ]        KO        KO	
#[-9223372036854775809 2 1 ]        KO        KO	

#Repeated Numbers
#[-1 -1 2                  ]        KO        KO	???
#[+1 1 2                   ]        KO        KO	???
