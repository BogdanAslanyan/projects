#CFLAGS=-Wall -Werror -Wextra
CFLAGS = -Wall -Werror -Wextra -g 

all: clean s21_math.a test gcov_report

test: main.c s21_math.c
	gcc -o test $(CFLAGS) --coverage main.c s21_math.c -lcheck -lpthread -lm  -I /usr/local/include -L/usr/local/lib
	
s21_math.a: s21_math.o
	ar rc s21_math.a s21_math.o
	ranlib s21_math.a
	
s21_math.o: s21_math.c
	gcc $(CFLAGS) -c s21_math.c -o s21_math.o
	

gcov_report:
	./test
	gcov main.c 
	gcov s21_math.c
	gcovr -r  . --html -o coverage.html
	
check:
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -i *.c
	clang-format -i *.h
	

clean:
	rm -rf *.o *.gcda *.a *.html *.gcno *.css *.gcov ./test.dSYM
	rm -f test
