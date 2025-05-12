# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 13:00:35 by svereten          #+#    #+#              #
#    Updated: 2025/05/12 20:19:54 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = ex00

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -MP -g

INCLUDE = -I./include

SRC_DIR = src
OBJ_DIR = obj

FILES = main \
		Animal \
		Cat \
		Dog \
		WrongAnimal \
		WrongCat \

OBJS = ${FILES:%=${OBJ_DIR}/%.o}
DEPS = ${FILES:%=${OBJ_DIR}/%.d}

OBJ_DIRS = ${sort ${dir ${OBJS}}}

DEBUG = 0

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} $^ -o $@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp | ${OBJ_DIRS}
	${CXX} ${CXXFLAGS} ${INCLUDE} -D DEBUG=${DEBUG} -c $< -o $@

${OBJ_DIRS}:
	mkdir -p $@

-include ${DEPS}

clean:
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -rf ${NAME}

re: fclean all

run: ${NAME}
	./${NAME} ${ARGS}

valgrind: ${NAME}
	valgrind ./${NAME} ${ARGS}

.PHONY: all clean fclean re run valgrind
