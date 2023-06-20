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

NAME			:= philo
UNIT_OUT		:= test.out
SRC_DIR			:= src
BUILD_DIR		:= build
MAIN			:= main.c
INCLUDE_DIR		:= include
RM				:= rm -rvf

HEADERS			= $(INCLUDE_DIR)/philo.h
CC				= gcc

################################################################################

CFLAGS			= -Wall -Wextra -Werror -Wpedantic
INCLUDE_FLAGS	:= $(addprefix -I, $(sort $(dir $(HEADERS))))
CRIT_FLAG		= -lcriterion

ifdef	DEBUG
	CFLAGS		+=-g
endif

ifdef	FSAN
	CFLAGS		+=-fsanitize=address,undefined
endif

ifdef	THRD
	CFLAGS		+=-fsanitize=thread
endif

################################################################################

# Source files
SRC = \
  utils/ft_atol_with_overflow.c \
  utils/ft_memcpy.c \
  utils/prepare_arguments.c \
  thread/thread_print_result.c \
  thread/thread_join.c \
  thread/thread_create.c \
  utils/parser.c \
  thread/thread_main.c \
  thread/thread_new.c \
  utils/ft_usleep.c \
  thread/thread_routine.c \
  actions/diner.c \
  actions/sleeping.c \
  initialize/initialize_time.c \
  utils/lock_print_unlock.c \
  utils/check_if_alive.c \
  initialize/initialize_philos.c \
  utils/stop_now.c
#  initialize/initialize.c \

TEST_SRC = \
  src/utils/parser.c

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

unit_test: $(UNIT_OUT) all
.PHONY: unit_test

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $^ $(INCLUDE_FLAGS) -o $(NAME)
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"

$(MAIN_OBJ) $(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

################################################################################

$(UNIT_OUT):
	$(CC) $(CFLAGS) $(CRIT_FLAG) $(INCLUDE_FLAGS) $(INC_UNIT) $(LIB_UNIT) $(TEST_SRC) $(UNIT_SRC) -o $(UNIT_OUT)
	@printf "$(BLUE_FG)$(UNIT_OUT)$(RESET_COLOR) created\n"
	@#$(RM) test.* unit_test/include/*.gch

test:
	@$(MAKE) DEBUG=1 FSAN=1 unit_test
	@./$(UNIT_OUT)
.PHONY: test

retest: fclean test
.PHONY: retest

uclean:
	@$(RM) test.* unit_test/include/*.gch

clean:
	@$(RM) $(OBJS) $(MAIN_OBJ)

debug:
	$(MAKE) DEBUG=1
.PHONY: debug

rebug: fclean debug
.PHONY: rebug

fsan:
	$(MAKE) DEBUG=1 FSAN=1
.PHONY: debug

resan: fclean fsan
.PHONY: resan

fclean: clean

re: fclean all

.PHONY: all clean fclean re
