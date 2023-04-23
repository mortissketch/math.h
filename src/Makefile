CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
TST_LIBS = -lcheck
UNAME:= $(shell uname)
ifeq ($(UNAME), Linux)
	TST_LIBS += -lpthread -lrt -lsubunit -lm
endif

SRCS=$(wildcard s21_*.c)

OBJS=$(SRCS:.c=.o)

LIB_NAME = s21_math

all: clean gcov_report

clean:
	rm -rf *.o test *.a *.gcno *.gcda *.gcov *.html *.css

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIB_NAME).a: $(OBJS)
	ar rc $(LIB_NAME).a $^
	ranlib $(LIB_NAME).a
	rm -rf *.o
linter:
	python3 ../cpplint.py --extensions=c *.c *.h 

# check - либа для работы тестов, s21_math - наша либа
test: clean $(LIB_NAME).a
	$(CC) $(FLAGS) ./tests/s21_test.c -L. $(LIB_NAME).a $(TST_LIBS) -o test
add_coverage_flag:
	$(eval FLAGS += --coverage)

gcov_report: add_coverage_flag test
	./test
	gcov -b -l -p -c s21_*.gcno
	gcovr -o gcov_report.html --html --html-details # -g -k -r . --html --html-details