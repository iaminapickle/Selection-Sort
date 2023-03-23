CC = gcc
CFLAGS = -c -Wall
VPATH = ../../../Helper

all: unstable_bidirectional_selection_sort.o stable_bidirectional_selection_sort.o

unstable_bidirectional_selection_sort.o: unstable_bidirectional_selection_sort.c Tuple.h TupleArr.h
	$(CC) $(CFLAGS) $^

stable_bidirectional_selection_sort.o: stable_bidirectional_selection_sort.c Tuple.h TupleArr.h
	$(CC) $(CFLAGS) $^

clean:
	rm *.o
