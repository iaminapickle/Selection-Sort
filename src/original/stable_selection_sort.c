#include "../helper/Tuple.h"
#include "../helper/TupleArr.h"
#include <stdio.h>
#include <stdlib.h>

void stableSelectionSort(TupleArr *tupleArr) {
  Tuple *arr = tupleArr->arr;
  int size = tupleArr->size;
  
  for (int i = 0; i < size; i++) {
    int min_index = findMinIndex(arr, i, size);
    Tuple temp = arr[min_index];

    if (min_index != i) {
      moveAcrossRight(arr, i, min_index);
      arr[i] = temp;
    }
  }
}
