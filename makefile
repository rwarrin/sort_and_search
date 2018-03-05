all:
	clang -Wall -Werror -Wno-null-dereference -Wextra -pedantic -O0 main.c -g -ggdb

clean:
	rm *.out
