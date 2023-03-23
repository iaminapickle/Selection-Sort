#ifndef TUPLEARRWRAPPER_H
#define TUPLEARRWRAPPER_H

#include "Tuple.h"

typedef struct tuple_arr_wrapper_struct {
  Tuple *arr;
  int size;
} TupleArr;

TupleArr *genRandomTupleArr(int size, int max);
int findMinIndex(Tuple *tuple_arr, int start, int end);
void findMinMaxIndex(Tuple *arr, int start, int end, int *minIndex, int *maxIndex);
void moveAcrossRight(Tuple *tuple_arr, int start, int end);
void moveAcrossLeft(Tuple *tuple_arr, int start, int end);
void printTupleArr(Tuple *arr, int size);
TupleArr *manualTupleArr(void);
#endif
