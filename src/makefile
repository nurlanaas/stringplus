CC=gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 $(shell pkg-config --cflags check)
CFLAGS_Docker = -Wall -Werror -Wextra -std=c11
CFILES = $(wildcard *.c)
OFILES = $(patsubst %.c,%.o, ${CFILES})
TESTS_CFILES = tests/*.c
OS_NAME = $(shell uname -s)

ifeq ($(OS_NAME),Linux) 
	LIB_FLAGS = $(shell pkg-config --libs check)
endif
ifeq ($(OS_NAME),Darwin)
	LIB_FLAGS =
endif

all: s21_string.a

do_allsan: s21_string.a testsan gcov_report

testsan: s21_string.a
	${CC} $(CFLAGS) -o test $(TESTS_CFILES) s21_string.a $(LIB_FLAGS) -lcheck -fsanitize=address

do_all: s21_string.a test gcov_report

s21_string.a: ${CFILES}
	${CC} -c $(CFLAGS) $(LIB_FLAGS) $(CFILES)
	ar rcs $@ $(OFILES)
	ranlib s21_string.a
	-rm -rf *.o
	
test: s21_string.a
	${CC} $(CFLAGS) -o test $(TESTS_CFILES) s21_string.a $(LIB_FLAGS) -lcheck
	./test

gcov_report:${CFILES}
	gcc --coverage ${CFILES} ${TESTS_CFILES} -o test $(LIB_FLAGS) -lcheck
	./test
	lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info

clean:
	-rm -rf *.o *.gcda *.gcno *.gcov *result coverage.info s21_test.info s21_string.a test report

clang:
	cp ../materials/linters/.clang-format .
	clang-format -i -style=Google ${CFILES} ${TESTS_CFILES} *.h tests/*.h
	clang-format -n -style=Google ${CFILES} ${TESTS_CFILES} *.h tests/*.h
	rm .clang-format

rebuild: clean all