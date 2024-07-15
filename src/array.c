#include "include/array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Array arrayNew(int itemSize)
{
  Array array = (Array){
      .items = calloc(4, itemSize),
      .size = 0,
      .capacity = 4,
      .itemSize = itemSize};
  return array;
}

int arrayFindString(Array *array, char *str)
{
  for (int index = 0; index < array->size; index++)
  {
    if (strcmp(arrayAt(array, index), str) == 0)
    {
      return index;
    }
  }
  return -1;
}

void *arrayAt(Array *array, int index)
{
  if (index < 0 || index >= array->size)
  {
    fprintf(stderr, "Index out of bounds: tried to access %d of [%s]\n", index, arrayToString(array));
    exit(1);
  }
  return array->items + array->itemSize * index;
}

char *arrayToString(Array *array)
{
  char *str = calloc(100, sizeof(char)), *item;
  str[0] = '\0';

  for (int index = 0; index < array->size; index++)
  {
    item = arrayAt(array, index);
    strcat(str, item);
    if (index < array->size - 1)
      strcat(str, ",");
  }

  return str;
}

void arrayAppend(Array *array, void *item)
{
  if (array->size == array->capacity)
  {
    array->capacity *= 2;
    array->items = realloc(array->items, array->itemSize * array->capacity);
  }
  array->size += 1;
  memcpy(arrayAt(array, array->size - 1), item, array->itemSize);
}

void arrayRemove(Array *array, int index)
{
  memcpy(arrayAt(array, index), array->items + array->itemSize * (index + 1), array->itemSize * (array->size - index));
  array->size -= 1;
}
