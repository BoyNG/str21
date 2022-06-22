.PHONY: all clean test s21_string.a check gcov_report valgrind

CC = gcc
CC2 = gcc
CFLAGS = -c -Wall -Wextra -Werror
PROFILE_FLAGS = -fprofile-arcs -ftest-coverage
TST_LIBS = -lcheck -lm -lpthread
COV_LIBS = -lgcov -coverage  
GCOV = gcovr 
GCONV_FLAGS = -r . --html --html-details 
OS := $(shell uname -s)

ifeq ($(OS), Darwin)
	CC2 += -D OS_MAC
else
	CC2 += -D OS_LINUX
endif
default: all

all: clean s21_string.a test gcov_report

test: s21_string.a
ifeq ($(OS), Darwin)
	$(CC) -o test unit_tests.c s21_string.a -lcheck -lgcov -coverage
	./test
else
	$(CC) -o test unit_tests.c s21_string.a -lcheck -lsubunit -lrt -lpthread -lm -lgcov -coverage
	./test
endif

s21_string.a: s21_string.o s21_sprintf.o
	ar rcs s21_string.a s21_string.o s21_sprintf.o
	ranlib s21_string.a

s21_string.o:  s21_string.c s21_string.h errlist.h
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) s21_string.c

s21_sprintf.o:  s21_string.c s21_sprintf.c s21_string.h errlist.h
	$(CC) $(CFLAGS) $(PROFILE_FLAGS)  s21_sprintf.c 

clean:
	-rm -rf test *.out *.o *.a *.cfg fizz *.gc* *.info report unit_tests RESULT_VALGRIND.txt

rebuild: clean all

check:
	cppcheck *.h *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	rm CPPLINT.cfg

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./test

gcov_report:
ifeq ($(OS), Darwin)
	$(CC2) --coverage -fprofile-arcs -ftest-coverage unit_tests.c s21_string.c s21_sprintf.c -o test -lcheck
else 
	$(CC2) --coverage -fprofile-arcs -ftest-coverage unit_tests.c s21_string.c s21_sprintf.c -o test  -lcheck -lsubunit -lrt -lpthread -lm
endif
	./test
	lcov -t "test" -o test.info -c -d ./
	genhtml -o report test.info
ifeq ($(OS), Darwin)
	open ./report/index-sort-f.html
else
	xdg-open ./report/index-sort-f.html
endif
	rm -rf ./*.gcno ./*.gcda ./GcovReport.* 
