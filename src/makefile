CC=gcc

CFLAGS= -std=c11 -Wall -Werror -Wextra -pedantic -O2
CGCOV= -fprofile-arcs -ftest-coverage

BUILD_DIR= ../build/
COVR_REPORT_FNAME= coverage_report.html
LCOV_REPORT_DIR= coverage_report/


TESTS= tests/check_main.c\
				tests/check_s21_string.c\
				tests/check_utils.c\

SRC= s21_string.c\
				utils/write_int_into_str_buffer.c\

OBJ= $(SRC:%.c=%.o)

CHECKLIBS= -lcheck -lm -lpthread -lrt

.PHONY: rebuild clean test_source lcov_gen_html gcovr_gen_html

# **************************************************************************
# =====================COMMANDS===FOR===USAGE===============================
# **************************************************************************

all: clean test_source gcov_report

test: test_source

s21_string.a: libs21_string.a

gcov_report: lcov_gen_html

clean:
	rm -rf $(BUILD_DIR)* *.a *.gcda *.gcno *.html $(LCOV_REPORT_DIR)

rebuild:
	$(MAKE) clean
	$(MAKE) all

test_lib: silently_test_library

# ==========================================================================

lcov_gen_html: test_source
	mkdir $(LCOV_REPORT_DIR)
	lcov -t "s21_string_test" -o $(LCOV_REPORT_DIR)s21_string_lcov.info -c -d .
	genhtml -o $(LCOV_REPORT_DIR) $(LCOV_REPORT_DIR)s21_string_lcov.info
	ln -s $(LCOV_REPORT_DIR)index.html $(COVR_REPORT_FNAME)
	rm *.gcno *.gcda

gcovr_gen_html: test_source
	gcovr -r . --html --html-details -o $(COVR_REPORT_FNAME)
	mkdir coverage_report
	mv *.html ./coverage_report/
	ln -s $(LCOV_REPORT_DIR)coverage_report.html $(COVR_REPORT_FNAME)
	rm *.gcno *.gcda

test_source: $(TESTS)
	$(CC) $(FLAGS) $(CGCOV) $(TESTS) $(SRC) \
		`pkg-config --cflags --libs check` -o $(BUILD_DIR)s21_string_test
	$(BUILD_DIR)s21_string_test
	

silently_test_library: $(TESTS) libs21_string.a
	$(CC) $(FLAGS) $(TESTS) -L. -ls21_string \
		`pkg-config --cflags --libs check` -o $(BUILD_DIR)s21_string_test
	$(BUILD_DIR)s21_string_test

libs21_string.a:
	$(CC) -c $(FLAGS) $(SRC)
	mv *.o $(BUILD_DIR)
	ar rc libs21_string.a $(BUILD_DIR)s21_string.o
	ranlib libs21_string.a


# ==========================================================================

# **************************************************************************
# +++++++++++++++++++++++++++++++SOURCES++++++++++++++++++++++++++++++++++++
# **************************************************************************
# 
# создание библиотеки
# https://firststeps.ru/linux/r.php?5
# https://stackoverflow.com/questions/60590641/makefile-to-compile-all-src-and-generate-static-library
# 
# заставить собираться check.h 
# https://stackoverflow.com/questions/9716704/building-the-library-for-check-test-c-framework
# 
# gcovr (make html report)
# https://www.ccs.neu.edu/home/skotthe/classes/cs5600/f11all/2015/labs/intro-check.html
# 
# lcov tuttorial
# https://ps-group.github.io/cxx/coverage_gcc
# 
# makefile
# https://habr.com/ru/post/211751/
