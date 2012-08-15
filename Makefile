CC=g++
CFLAGS=-g

all: test


test: cuminotest
	./cuminotest


cuminotest: cumino.o test.o
	g++ -o cuminotest cumino.o test.o


cumino.o : cumino.c
	$(CC) $(CFLAGS) -c -o cumino.o cumino.c

test.o : test.c
	$(CC) $(CFLAGS) -c -o test.o test.c


clean:
	rm test *.o
