NAME = push_swap
SRC = source/main.c source/lists.c source/checknum.c source/instructions.c \
		source/instructions_a.c source/instructions_b.c source/instructions_ab.c \
		source/test.c source/radix.c source/savelist.c

OBJ = $(SRC:.c=.o)
#-fsanitize=address
FLAGS = -Wall -Wextra -Werror -Iinclude
DEBUG_FLAGS = -g -fsanitize=address -Iinclude

LIB = libft

# Colors for pretty output
GREEN = \033[0;32m
YELLOW = \033[1;33m
RED = \033[0;31m
NC = \033[0m # No Color

all: ${NAME}

${NAME}: ${OBJ}
		@make -C $(LIB)
		@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB)/libft.a
		@echo "$(GREEN)✅ Push Swap compiled successfully!$(NC)"

${NAME}_debug: ${OBJ}
		@make -C $(LIB)
		@gcc $(DEBUG_FLAGS) $(OBJ) -o $(NAME) $(LIB)/libft.a
		@echo "$(YELLOW)⚠️  Push Swap compiled with debug flags!$(NC)"

#$(OBJ): $(SRC)
#		@gcc $(FLAGS) -c $(SRC)

# Test cases
test3: all
		@echo "$(YELLOW)🧪 Testing with 3 elements:$(NC)"
		@./$(NAME) 1 3 2

test5: all
		@echo "$(YELLOW)🧪 Testing with 5 elements:$(NC)"
		@./$(NAME) 2 1 4 3 5

test100: all
		@echo "$(YELLOW)🧪 Testing with 100 random elements:$(NC)"
		@shuf -i 1-100 -n 100 | tr '\n' ' ' | xargs ./$(NAME) | wc -l

test500: all
		@echo "$(YELLOW)🧪 Testing with 500 random elements:$(NC)"
		@shuf -i 1-500 -n 500 | tr '\n' ' ' | xargs ./$(NAME) | wc -l

# Run tests
tests: test3 test5 test100 test500
		@echo "$(GREEN)✅ All tests completed!$(NC)"

# Compile and run with default test
exe: all test5

# Compile with debug and run
debug: ${NAME}_debug test5
		@echo "$(YELLOW)⚠️  Debug mode active$(NC)"

# Clean object files
clean:
		@rm -rf $(OBJ)
		@make -C $(LIB) clean
		@echo "$(YELLOW)🧹 Object files cleaned$(NC)"

# Clean everything
fclean: clean
		@rm -rf $(NAME)
		@make -C $(LIB) fclean
		@echo "$(RED)🗑️  All files cleaned$(NC)"

# Compile tests
comp: fclean exe

# Recompile everything
re: fclean all
		@echo "$(GREEN)🔄 Project recompiled$(NC)"

# Help target
help:
		@echo "$(GREEN)Push Swap - Available targets:$(NC)"
		@echo "  make         - Compile the project"
		@echo "  make debug   - Compile with debug flags"
		@echo "  make test3   - Test with 3 elements"
		@echo "  make test5   - Test with 5 elements"
		@echo "  make test100 - Test with 100 elements"
		@echo "  make test500 - Test with 500 elements"
		@echo "  make tests   - Run all tests"
		@echo "  make exe     - Compile and run default test"
		@echo "  make clean   - Clean object files"
		@echo "  make fclean  - Clean everything"
		@echo "  make re      - Recompile everything"
		@echo "  make help    - Show this help message"

.PHONY: clean fclean all re test3 test5 test100 test500 tests exe debug help