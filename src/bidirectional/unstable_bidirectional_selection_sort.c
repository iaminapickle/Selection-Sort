#include "../../../Helper/TupleArr.h"
#include "../../../Helper/Tuple.h"
#include <stdio.h>
#include <stdlib.h>

void unstableBidirectionalSelectionSort(TupleArr *tupleArr) {
  Tuple *arr = tupleArr->arr;
  int size = tupleArr->size;
  
  int minIndex, maxIndex;
  for (int i = 0; i < size / 2; i++) {
    findMinMaxIndex(arr, i, size, &minIndex, &maxIndex);
    if (i == maxIndex) {
      maxIndex = minIndex;
    }

    swapTuple(&arr[i], &arr[minIndex]);
    swapTuple(&arr[size - i - 1], &arr[maxIndex]);
  }
}
