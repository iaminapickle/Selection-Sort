#include "../../../Helper/TupleArr.h"
#include "../../../Helper/Tuple.h"
#include <stdio.h>
#include <stdlib.h>

void unstableSelectionSort(TupleArr *tupleArr) {
  Tuple *arr = tupleArr->arr;
  int size = tupleArr->size;
  for (int i = 0; i < size; i++) {
    int index = findMinIndex(arr, i, size);
    swapTuple(&arr[i], &arr[index]);
  }
}
