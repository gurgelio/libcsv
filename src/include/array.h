#ifndef ROW_H
#define ROW_H
#include <stddef.h>

typedef struct
{
  void *items;
  int size, capacity, itemSize;
} Array;

int arrayFindString(Array *array, char *str);

Array arrayNew(int itemSize);

void *arrayAt(Array *array, int index);

char *arrayToString(Array *array);

void arrayAppend(Array *array, void *item);

void arrayRemove(Array *array, int index);

void arrayFree(Array *array);

#endif