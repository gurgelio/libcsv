#include "include/csv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Csv csvNew()
{
  Csv csv = (Csv){
      .rows = arrayNew(sizeof(Array)),
      .headers = arrayNew(sizeof(char *))};

  return csv;
}

char *csvToString(Csv *csv)
{
  char *acc = arrayToString(&csv->headers), *rowStr;

  for (int index = 0; index < csv->rows.size; index++)
  {
    rowStr = arrayToString(arrayAt(&csv->rows, index));

    acc = realloc(acc, (strlen(acc) + strlen(rowStr) + 1) * sizeof(char));
    strcat(acc, "\n");
    strcat(acc, rowStr);
  }
  return acc;
}

void csvRemoveColumn(Csv *csv, int index)
{
  arrayRemove(&csv->headers, index);
  for (int row = 0; row < csv->rows.size; row++)
  {
    arrayRemove(arrayAt(&csv->rows, row), index);
  }
}