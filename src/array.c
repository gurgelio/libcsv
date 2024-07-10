#include "include/array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Array arrayNew(size_t itemSize)
{
  return (Array){
      .items = calloc(1, itemSize),
      .size = 0,
      .capacity = 1,
      .itemSize = itemSize};
}

void *arrayAt(Array *array, size_t index)
{
  if (index >= array->size)
  {
    fprintf(stderr, "Index out of bounds: tried to access %ld of %s\n", index, arrayToString(array));
    exit(1);
  }
  return array->items + array->itemSize * index;
}

Str arrayToString(Array *array)
{
  Str str = calloc(1, sizeof(char)), item;
  str[0] = '\0';

  for (size_t index = 0; index < array->size; index++)
  {
    item = arrayAt(array, index);
    str = realloc(str, (strlen(str) + strlen(item) + 1) * sizeof(char));
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
  memcpy(&array->items + array->itemSize * array->size++, item, array->itemSize);
}
