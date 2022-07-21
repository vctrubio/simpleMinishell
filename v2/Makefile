# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 20:08:59 by joaribei          #+#    #+#              #
#    Updated: 2022/07/05 16:27:18 by V                ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#name fo the project
NAME = minishell

# Color variables
GRN = \033[0;32m
GRNGRN = \033[38;5;46m
RED = \033[0;31m
RST = \033[0m

# Variables for path s of source, header
INC_DIR = ./includes
SRC_DIR = ./sources

SRCS =	${SRC_DIR}/minishell.c \
		${SRC_DIR}/char/char.c \
		${SRC_DIR}/char/util_1.c \
		${SRC_DIR}/char/util_2.c \
		${SRC_DIR}/command/command.c \
		${SRC_DIR}/command/util_1.c \
		${SRC_DIR}/command/util_2.c \
		${SRC_DIR}/command/util_3.c \
		${SRC_DIR}/command/util_4.c \
		${SRC_DIR}/env/env.c \
		${SRC_DIR}/memory/memory.c \
		${SRC_DIR}/memory/util_1.c \
		${SRC_DIR}/memory/util_2.c \
		${SRC_DIR}/memory/util_3.c \
		${SRC_DIR}/string/string.c \
		${SRC_DIR}/string/util_1.c \
		${SRC_DIR}/string/util_2.c \
		${SRC_DIR}/string/util_3.c \
		${SRC_DIR}/string/util_4.c \
		${SRC_DIR}/string/util_5.c \
		${SRC_DIR}/string/util_6.c \
		${SRC_DIR}/parse/dquote.c \
		${SRC_DIR}/parse/parse.c \
		${SRC_DIR}/parse/util_array.c \
		${SRC_DIR}/parse/util_debuging.c \
		${SRC_DIR}/parse/util_parse.c \
		${SRC_DIR}/parse/util_str.c \
		${SRC_DIR}/static/shell.c \
		${SRC_DIR}/prompt/prompt.c \
		${SRC_DIR}/termios/termios.c \

# Variables for path of object files and binary targets
BUILD_DIR = ./build
OBJ_DIR = ${BUILD_DIR}/obj
BIN_DIR = ${BUILD_DIR}/bin
BIN = ${BIN_DIR}/${NAME}
OBJS = $(subst .c,.o,$(subst ${SRC_DIR},${OBJ_DIR},${SRCS}))

# Variables for compiler configs
CC = gcc
CFLAGS = -Werror -Wall -Wextra
INCLUDES = -I$(INC_DIR)

all: ${BUILD_DIR} ${NAME}

$(NAME): ${OBJS}
	@$(CC) $(CFLAGS) -lreadline $^ -o $(BIN)

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@mkdir -p ${dir $@}
	$(CC) $(CFLAGS) -I${INC_DIR} -c $< -o  $@
	@echo "$(GRNGRN)/$(RST)\c"

${BUILD_DIR}:
	@mkdir -p ${BUILD_DIR}
	@mkdir -p ${BIN_DIR}
	@mkdir -p ${OBJ_DIR}

run: all
	@echo "Running ${NAME}"
	@./${BIN}

clean:
	@rm -rf $(OBJ_DIR)
	@printf "\e[31mclean done\e[0m\n"

fclean:
	@rm -rf $(BUILD_DIR)
	@printf "$(RED)fclean done\e[0m\n"

re:		fclean all

.PHONY: all run clean fclean re
