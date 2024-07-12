#ifndef ROW_H
#define ROW_H
#include <stddef.h>

typedef struct
{
  void *items;
  size_t size, capacity, itemSize;
} Array;

Array arrayNew(size_t itemSize);

void *arrayAt(Array *array, size_t index);

char *arrayToString(Array *array);

void arrayAppend(Array *array, void *item);

void arrayFree(Array *array);

#endif