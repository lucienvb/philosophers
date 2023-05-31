# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lvan-bus <lvan-bus@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/24 13:17:24 by lvan-bus      #+#    #+#                  #
#    Updated: 2023/05/24 13:17:26 by lvan-bus      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include makerc/colors.mk

################################################################################

NAME          := philo
UNIT_OUT      := test.out
SRC_DIR       := src
BUILD_DIR     := build
MAIN          := main.c
INCLUDE_DIR   := include
RM            := rm -rvf

HEADERS       = $(INCLUDE_DIR)/philo.h
CC            = gcc

################################################################################

CFLAGS        = -Wall -Wextra -Werror$(if $(FSAN), -g -fsanitize=thread)$(if $(DEBUG), -g)
WFLAGS        = -Wall -Wextra -Werror
FSAN          = -fsanitize=address,undefined
BEEBOE        = -g -MMD -MP
INCLUDE_FLAGS := $(addprefix -I, $(sort $(dir $(HEADERS))))
CRIT_FLAG     = -lcriterion

################################################################################

# Source files
SRC = \
  thread/thread_main.c \
  utils/ft_atol_with_overflow.c \
  utils/ft_memcpy.c \
  thread/thread_print_result.c \
  thread/thread_join.c \
  thread/thread_create.c \
  thread/thread_routine.c \
  initialize/initialize.c

TEST_SRC = \
  src/test.c

UNIT_SRC = \
  unit_test/src/philo_test.c

################################################################################

# Object files
OBJS       = $(addprefix $(BUILD_DIR)/, $(SRC:%.c=%.o))
MAIN_OBJ   = $(addprefix $(BUILD_DIR)/, $(MAIN:%.c=%.o))

################################################################################

# Include directories
INC_UNIT = -I/Users/lucienvanbussel/.brew/cellar/criterion/2.4.1_2/include

# Criterion library
LIB_UNIT = -L/Users/lucienvanbussel/.brew/cellar/criterion/2.4.1_2/lib

################################################################################

all: $(NAME)

$(NAME): SHELL :=/bin/bash

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $^ $(INCLUDE_FLAGS) -o $(NAME)
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"

$(MAIN_OBJ) $(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

################################################################################

test:
	$(CC) $(WFLAGS) $(BEEBOE) $(FSAN) $(CRIT_FLAG) $(INC_UNIT) $(LIB_UNIT) $(TEST_SRC) $(UNIT_SRC) -o $(UNIT_OUT)
	@printf "$(BLUE_FG)$(UNIT_OUT)$(RESET_COLOR) created\n"
	@./$(UNIT_OUT)
.PHONY: test

uclean:
	@$(RM) test.* unit_test/include/*.gch

clean:
	@$(RM) $(OBJS) $(MAIN_OBJ)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
