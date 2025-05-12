# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 12:13:43 by svereten          #+#    #+#              #
#    Updated: 2025/05/12 19:09:40 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = ex03

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -MMD -MP -g

INCLUDE = -I./include

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = test

FILES = MateriaSource \
		AMateria \
		Ice \
		Cure \
		Character \
		Floor \

OBJS = ${FILES:%=${OBJ_DIR}/%.o}
DEPS = ${FILES:%=${OBJ_DIR}/%.d}

OBJ_DIRS = ${sort ${dir ${OBJS}}}

#TESTS = ${FILES:%=${TEST_DIR}/%}
TESTS = test/AMateria \
		test/Character \
		test/Cure \
		test/Floor \
		test/Ice \
		test/MateriaSource \

#TEST_OBJS = ${FILES:%=${OBJ_DIR}/test%.o}
TEST_OBJS = obj/testAMateria.o \
			obj/testCharacter.o \
			obj/testCure.o \
			obj/testFloor.o \
			obj/testIce.o \
			obj/testMateriaSource.o \
			${filter-out obj/main.o, ${OBJS}}

TEST_DIRS = ${sort ${dir ${TESTS}}}


DEBUG = 0

all: ${NAME}

${NAME}: ${OBJS} ${OBJ_DIR}/main.o
	${CXX} ${CXXFLAGS} $^ -o $@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp | ${OBJ_DIRS}
	bear --append -- ${CXX} ${CXXFLAGS} ${INCLUDE} -D DEBUG=${DEBUG} -c $< -o $@

${OBJ_DIRS}:
	mkdir -p $@

-include ${DEPS}

tests: test/bin
	valgrind ./test/bin

test/bin: ${TEST_OBJS}
	mkdir -p test
	${CXX} ${CXXFLAGS} $^ -o test/bin -I/usr/src/googletest/googletest/include \
    -L/usr/lib \
    -lgtest -lgtest_main -pthread

test%: ${TEST_DIR}/%
	valgrind ./$<

${TEST_DIR}/%: ${OBJ_DIR}/test%.o ${OBJS} | ${TEST_DIRS}
	${CXX} ${CXXFLAGS} $^ -o $@ -I/usr/src/googletest/googletest/include \
    -L/usr/lib \
    -lgtest -lgtest_main -pthread

${TEST_DIRS}:
	mkdir -p $@

print:
	echo ${TEST_OBJS}

clean:
	rm -rf ${OBJ_DIR}
	rm -rf compile_commands.json

fclean: clean
	rm -rf ${NAME}
	rm -rf ${TEST_DIR}

re: fclean all

run: ${NAME}
	./${NAME} ${ARGS}

valgrind: ${NAME}
	valgrind --leak-check=full --show-leak-kinds=all ./${NAME} ${ARGS}

.PHONY: all clean fclean re run valgrind
