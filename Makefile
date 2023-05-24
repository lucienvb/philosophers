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

NAME 		:= philo
SRC_DIR		:= src
BUILD_DIR 	:= build
MAIN 		:= main.c
INCLUDE_DIR	:= include
HEADERS		= $(INCLUDE_DIR)/philo.h
RM			:= rm -rvf
CC 			= gcc

################################################################################

CFLAGS			=-Wall -Wextra -Werror$(if $(FSAN), -g -fsanitize=thread)$(if $(DEBUG), -g)
#FSAN = -fsanitize=address,undefined -g
INCLUDE_FLAGS	:=$(addprefix -I, $(sort $(dir $(HEADERS))))

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

################################################################################

# Object files
OBJS			=$(addprefix $(BUILD_DIR)/, $(SRC:%.c=%.o))
MAIN_OBJ		=$(addprefix $(BUILD_DIR)/, $(MAIN:%.c=%.o))

################################################################################

# Unit test files
#UNIT_SRC = unit_test/src/philo_test.c
#UNIT_OBJ = $(UNIT_SRC:.c=.o)

# Include directories
#INC_DIRS = -I./include -I./unit_test/include -I.
#INC_DIRS = -I.

# Criterion library
#CRITERION_LIB = -lcriterion

################################################################################

all: $(NAME)

$(NAME): SHELL :=/bin/bash

$(NAME): $(OBJS) $(MAIN_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(INCLUDE_FLAGS) -o $(NAME)
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"

$(MAIN_OBJ) $(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

################################################################################

# Unit test target
#test: $(UNIT_OBJ) $(OBJ)
#	$(CC) $(CFLAGS) $(FSAN) $(INC_DIRS) $(UNIT_OBJ) $(OBJ) $(CRITERION_LIB) -o $@
#	./$@

clean:
	@$(RM) $(OBJ) $(MAIN_OBJ)

fclean: clean
	@$(MAKE)

re: fclean
	@$(MAKE)

.PHONY: all clean fclean re
