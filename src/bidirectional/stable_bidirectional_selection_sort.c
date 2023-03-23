#include "../../../Helper/TupleArr.h"
#include "../../../Helper/Tuple.h"
#include <stdio.h>
#include <stdlib.h>

void stableBidirectionalSelectionSort(TupleArr *tupleArr) {
  Tuple* arr = tupleArr->arr;
  int size = tupleArr->size;

  int minIndex, maxIndex, left, right;
  Tuple tempMin, tempMax;
  for (int i = 0; i < size / 2; i++) {
    findMinMaxIndex(arr, i, size - i - 1, &minIndex, &maxIndex);
    tempMin = arr[minIndex];
    tempMax = arr[maxIndex];

    if (minIndex < maxIndex) {
      left = minIndex;
      right = maxIndex;
    } else {
      left = maxIndex;
      right = minIndex;
    }

    moveAcrossRight(arr, i, left);
    arr[i] = tempMin;

    moveAcrossLeft(arr, right, size - i - 1);
    arr[size - i - 1] = tempMax;
  }
}
