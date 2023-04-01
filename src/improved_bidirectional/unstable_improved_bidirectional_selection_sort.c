#include "../helper/TupleArr.h"
#include "../helper/Tuple.h"
#include <stdio.h>
#include <stdlib.h>

void unstableImprovedBidirectionalSelectionSort(TupleArr *tupleArr) {
  Tuple* arr = tupleArr->arr;
  int size = tupleArr->size;

  int min_q[size];
  int max_q[size];
  int i = 0;
  int j = size - 1;
  while (i < j) {
    int min = arr[i].n;
    int max = arr[i].n;

    int min_size = 0;
    int max_size = 0;
    for (int k = i; k < j + 1; k++) {
      if (arr[k].n < min) {
        min = arr[k].n;
        min_q[0] = k;
        min_size = 1;
      } else if (arr[k].n == min) {
        min_q[min_size] = k;
        min_size++;
      }

      if (arr[k].n > max) {
        max = arr[k].n;
        max_q[0] = k;
        max_size = 1;
      } else if (arr[k].n == max) {
        max_q[max_size] = k;
        max_size++;
      }
    }

    for (int l = 0; l < min_size; l++, i++) {
      if (arr[i].n == max) {
        for (int m = 0; m < max_size; m++) {
          if (max_q[m] == i) {
            max_q[m] = min_q[l];
            break;
          }
        }
       }
      swapTuple(&arr[min_q[l]], &arr[i]);
    }

    for (int l = 0; l < max_size; l++) {
      while (arr[j].n == max) {
        j--;
      }

      if (max_q[l] > j) {
        continue;
      }
      swapTuple(&arr[max_q[l]], &arr[j]);
    }
  }
}
