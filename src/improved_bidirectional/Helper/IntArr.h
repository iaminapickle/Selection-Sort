#ifndef INTARR_H
#define INTARR_H

typedef struct intarr_struct {
  int *arr;
  int size;
} IntArr;

IntArr *genRandomIntArr(int size, int max);

#endif
