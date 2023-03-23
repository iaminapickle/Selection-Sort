CC = gcc

CFLAGS = -c -Wall

all: Tuple.o TupleArr.o IntArr.o

Tuple.o: Tuple.c
	$(CC) $(CFLAGS) Tuple.c

TupleArr.o: TupleArr.c Tuple.h
	$(CC) $(CFLAGS) TupleArr.c

IntArr.o: IntArr.c
	$(CC) $(CFLAGS) IntArr.c

clean:
	rm *.o
