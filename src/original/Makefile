CC = gcc
CFLAGS = -c -Wall
VPATH = ../../../Helper

all: unstable_selection_sort.o stable_selection_sort.o

unstable_selection_sort.o: unstable_selection_sort.c Tuple.h TupleArr.h
	$(CC) $(CFLAGS) $^

stable_selection_sort.o: stable_selection_sort.c Tuple.h TupleArr.h
	$(CC) $(CFLAGS) $^

clean:
	rm *.o
