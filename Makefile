# Name of the executable
NAME = philo

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror
FSAN = -fsanitize=address,undefined -g

# Source files
SRC = \
	src/philosophers.c \
	src/thread/thread_main.c \
	src/utils/ft_atol_with_overflow.c \
	src/main.c \
	src/thread/thread_print_result.c \
	src/thread/thread_join.c \
	src/thread/thread_create.c \
	src/thread/thread_routine.c \
	src/initialize/initialize.c

OBJ = $(SRC:.c=.o)

# Unit test files
UNIT_SRC = unit_test/src/philo_test.c
UNIT_OBJ = $(UNIT_SRC:.c=.o)

# Include directories
#INC_DIRS = -I./include -I./unit_test/include -I.
INC_DIRS = -I.

# Criterion library
CRITERION_LIB = -lcriterion

# Default name
all: $(NAME)

# Main name
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(FSAN) $(INC_DIRS) $(OBJ) -o $(NAME)

# Unit test target
test: $(UNIT_OBJ) $(OBJ)
	$(CC) $(CFLAGS) $(FSAN) $(INC_DIRS) $(UNIT_OBJ) $(OBJ) $(CRITERION_LIB) -o $@
	./$@

# Clean up
clean:
	rm -f $(OBJ) $(UNIT_OBJ) $(NAME) test

fclean: clean
		rm -f $(NAME)

comp: all clean

re: fclean all

.PHONY: all clean fclean re