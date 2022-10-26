#name fo the project
NAME = minishell

# Color variables
GRN = \033[0;32m
GRNGRN = \033[38;5;46m
RED = \033[0;31m
RST = \033[0m

# Variables for path s of source, header
INC_DIR 	=	./includes
SRC_DIR 	=	./sources

CHAR		=	${SRC_DIR}/char
COMMAND		=	${SRC_DIR}/command
ENV			=	${SRC_DIR}/env
FILE		=	${SRC_DIR}/file
MEMORY		=	${SRC_DIR}/memory
PARSE		=	${SRC_DIR}/parse
SIGNAL		=	${SRC_DIR}/signal
STRING		=	${SRC_DIR}/string

SRCS		=	${CHAR}/is_alpha.c \
				${CHAR}/is_lowercase.c \
				${CHAR}/is_uppercase.c \
				${CHAR}/is_whitespace.c \
				${CHAR}/is_special_parse.c \
				${CHAR}/reference.c \
				${CHAR}/to_lower.c \
				${CHAR}/to_upper.c \
				${COMMAND}/add.c \
				${COMMAND}/cd.c \
				${COMMAND}/create.c \
				${COMMAND}/delete.c \
				${COMMAND}/echo.c \
				${COMMAND}/execute.c \
				${COMMAND}/export.c \
				${COMMAND}/function.c \
				${COMMAND}/g.c \
				${COMMAND}/greater_than.c \
				${COMMAND}/more_greater_than.c \
				${COMMAND}/name.c \
				${COMMAND}/pre_function.c \
				${COMMAND}/reference.c \
				${COMMAND}/system.c \
				${COMMAND}/token.c \
				${COMMAND}/unset.c \
				${ENV}/add.c \
				${ENV}/create.c \
				${ENV}/get.c \
				${ENV}/reference.c \
				${ENV}/size.c \
				${ENV}/to_double_pointer.c \
				${FILE}/close.c \
				${FILE}/create.c \
				${FILE}/reference.c \
				${MEMORY}/add.c \
				${MEMORY}/calloc.c \
				${MEMORY}/copy.c \
				${MEMORY}/free.c \
				${MEMORY}/malloc.c \
				${MEMORY}/realloc.c \
				${MEMORY}/reference.c \
				${MEMORY}/set.c \
				${PARSE}/dquote.c \
				${PARSE}/parse.c \
				${PARSE}/util_array.c \
				${PARSE}/util_debuging.c \
				${PARSE}/util_parse.c \
				${PARSE}/util_str.c \
				${SIGNAL}/reference.c \
				${STRING}/copy.c \
				${STRING}/dup.c \
				${STRING}/equals.c \
				${STRING}/is_quote.c \
				${STRING}/itoa.c \
				${STRING}/length.c \
				${STRING}/read_line.c \
				${STRING}/reference.c \
				${STRING}/split.c \
				${SRC_DIR}/minishell.c \

# Variables for path of object files and binary targets
BUILD_DIR	= 	./build
OBJ_DIR		= 	${BUILD_DIR}/obj
BIN_DIR		= 	${BUILD_DIR}/bin
BIN			= 	${BIN_DIR}/${NAME}
OBJS		= 	$(subst .c,.o,$(subst ${SRC_DIR},${OBJ_DIR},${SRCS}))

# Variables for compiler configs
CC			=	gcc
CFLAGS		=	-Werror -Wall -Wextra -g -fsanitize=address
INCLUDES	=	-I$(INC_DIR)

all: ${BUILD_DIR} ${NAME}

$(NAME): ${OBJS}
	@$(CC) $(CFLAGS) -lreadline $^ -o $(BIN)

exe: ${OBJS}
	@$(CC) $(CFLAGS) -lreadline $^ -o $(NAME)

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
#name fo the project
NAME = minishell

# Color variables
GRN = \033[0;32m
GRNGRN = \033[38;5;46m
RED = \033[0;31m
RST = \033[0m

# Variables for path s of source, header
INC_DIR 	=	./includes
SRC_DIR 	=	./sources

CHAR		=	${SRC_DIR}/char
COMMAND		=	${SRC_DIR}/command
ENV			=	${SRC_DIR}/env
FILE		=	${SRC_DIR}/file
MEMORY		=	${SRC_DIR}/memory
PARSE		=	${SRC_DIR}/parse
SIGNAL		=	${SRC_DIR}/signal
STRING		=	${SRC_DIR}/string

SRCS		=	${CHAR}/is_alpha.c \
				${CHAR}/is_lowercase.c \
				${CHAR}/is_uppercase.c \
				${CHAR}/is_whitespace.c \
				${CHAR}/is_special_parse.c \
				${CHAR}/reference.c \
				${CHAR}/to_lower.c \
				${CHAR}/to_upper.c \
				${COMMAND}/add.c \
				${COMMAND}/cd.c \
				${COMMAND}/create.c \
				${COMMAND}/delete.c \
				${COMMAND}/echo.c \
				${COMMAND}/execute.c \
				${COMMAND}/export.c \
				${COMMAND}/function.c \
				${COMMAND}/g.c \
				${COMMAND}/greater_than.c \
				${COMMAND}/more_greater_than.c \
				${COMMAND}/name.c \
				${COMMAND}/pre_function.c \
				${COMMAND}/reference.c \
				${COMMAND}/system.c \
				${COMMAND}/token.c \
				${COMMAND}/unset.c \
				${ENV}/add.c \
				${ENV}/create.c \
				${ENV}/get.c \
				${ENV}/reference.c \
				${ENV}/size.c \
				${ENV}/to_double_pointer.c \
				${FILE}/close.c \
				${FILE}/create.c \
				${FILE}/reference.c \
				${MEMORY}/add.c \
				${MEMORY}/calloc.c \
				${MEMORY}/copy.c \
				${MEMORY}/free.c \
				${MEMORY}/malloc.c \
				${MEMORY}/realloc.c \
				${MEMORY}/reference.c \
				${MEMORY}/set.c \
				${PARSE}/dquote.c \
				${PARSE}/parse.c \
				${PARSE}/util_array.c \
				${PARSE}/util_debuging.c \
				${PARSE}/util_parse.c \
				${PARSE}/util_str.c \
				${SIGNAL}/reference.c \
				${STRING}/copy.c \
				${STRING}/dup.c \
				${STRING}/equals.c \
				${STRING}/is_quote.c \
				${STRING}/itoa.c \
				${STRING}/length.c \
				${STRING}/read_line.c \
				${STRING}/reference.c \
				${STRING}/split.c \
				${SRC_DIR}/minishell.c \

# Variables for path of object files and binary targets
BUILD_DIR	= 	./build
OBJ_DIR		= 	${BUILD_DIR}/obj
BIN_DIR		= 	${BUILD_DIR}/bin
BIN			= 	${BIN_DIR}/${NAME}
OBJS		= 	$(subst .c,.o,$(subst ${SRC_DIR},${OBJ_DIR},${SRCS}))

# Variables for compiler configs
CC			=	gcc
CFLAGS		=	-Werror -Wall -Wextra -g -fsanitize=address
INCLUDES	=	-I$(INC_DIR)

all: ${BUILD_DIR} ${NAME}

$(NAME): ${OBJS}
	@$(CC) $(CFLAGS) -lreadline $^ -o $(BIN)

exe: ${OBJS}
	@$(CC) $(CFLAGS) -lreadline $^ -o $(NAME)

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
Makefile
build
includes
ls
lsd
newfil
sources
test.t
