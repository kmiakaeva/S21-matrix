SHELL = /bin/sh 

CFLAGS = -Wall -Werror -Wextra -std=c11 -g
CC = gcc
TFLAGS = -lcheck -lsubunit -lm
GFLAGS = --coverage -fprofile-arcs -ftest-coverage

SRC = utils/*.c conversion/*.c arithmetic/*.c operations/*.c
ALL_SRC = $(SRC) tests/*.c tests/suites/*.c

all: s21_matrix.a

rebuild: clean clear s21_matrix.a

s21_matrix.a: 
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc s21_matrix.a *.o

test: clear s21_matrix.a 
	$(CC) $(CFLAGS) $(ALL_SRC) s21_matrix.a $(TFLAGS) -o s21_tests
	./s21_tests

gcov_report: clear s21_matrix.a
	@$(CC) $(CFLAGS) $(ALL_SRC) s21_matrix.a $(TFLAGS) -o s21_gcov_r $(GFLAGS)
	@./s21_gcov_r > /dev/null 2>&1
	@lcov -t "gcov_report" -o s21_gcov_report.info -c -d . > /dev/null 2>&1
	@lcov -q -r s21_gcov_report.info '*/utils/*' '*/tests/*' -o s21_gcov_report.info > /dev/null 2>&1
	lcov -l s21_gcov_report.info
	@genhtml -o report s21_gcov_report.info > /dev/null 2>&1

clean:
	rm -rf report report s21_tests s21_gcov_r
	rm -rf s21_gcov *.gcno *.gcda *.info *.html *.css *.png *.deb *.a *.o

clear:
	clear

clang-format:
	clang-format -i $(ALL_SRC) *.h tests/*.h

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./s21_tests

.PHONY: all rebuild test gcov_report clean clear clang-format valgrind