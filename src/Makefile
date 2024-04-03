SHELL = /bin/sh 

CFLAGS = -Wall -Werror -Wextra -std=c11 -g
CC = gcc
TFLAGS = -lcheck -lsubunit -lm
GFLAGS = -fprofile-arcs -ftest-coverage
VLGRND = valgrind --tool=memcheck --leak-check=yes --show-leak-kinds=all --track-origins=yes -s

SRC = $(wildcard s21_*.c)
TEST_PATH = $(wildcard tests/s21_*.c)
OBJ = $(SRC:.c=.o)
TEST_OBJ = $(TEST_PATH:.c=.o)

all: clear s21_matrix run

s21_matrix:
	$(CC) $(CFLAGS) $(SRC) $(TEST_PATH) -o s21_matrix $(TFLAGS)

run:
	./s21_matrix

rebuild: clean all

clang-format:
	clang-format -i *.c tests/*.c *.h tests/*.h

clear:
	clear

clean:
	rm s21_matrix
