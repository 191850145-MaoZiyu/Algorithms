CC = g++
OP ?=
CFLAGS = $(OP) -Wall -Werror -std=c++17 -o
DEBUG = -D__DEBUG__
test:
	$(CC) $(CFLAGS) test.out test.cpp sort.cpp $(DEBUG) && ./test.out
clean:
	rm -f *.out
