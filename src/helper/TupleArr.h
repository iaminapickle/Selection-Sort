#ifndef TUPLEARRWRAPPER_H
#define TUPLEARRWRAPPER_H

#include "Tuple.h"

typedef struct tuple_arr_struct {
  Tuple *arr;
  int size;
} TupleArr;

TupleArr *initTupleArr(int size);
TupleArr *genRandomTupleArr(int size, int max, int seed);
void randomiseTuples(TupleArr *tupleArr, int size, int max, int seed);
TupleArr *manualTupleArr(void);

int findMinIndex(Tuple *tuple_arr, int start, int end);
void findMinMaxIndex(Tuple *arr, int start, int end, int *minIndex, int *maxIndex);

void moveAcrossRight(Tuple *tuple_arr, int start, int end);
void moveAcrossLeft(Tuple *tuple_arr, int start, int end);

void printTupleArr(Tuple *arr, int size);
void freeTupleArr(TupleArr* tupleArr);
#endif
