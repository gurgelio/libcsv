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

  for (size_t index = 0; index < csv->rows.size; index++)
  {
    rowStr = arrayToString(csvGetRow(csv, index));

    acc = realloc(acc, (strlen(acc) + strlen(rowStr) + 1) * sizeof(char));
    if (acc == NULL)
      fprintf(stderr, "failed to alloc\n");
    strcat(acc, "\n");
    strcat(acc, rowStr);
  }
  return acc;
}

Array *csvGetRow(Csv *csv, size_t index)
{
  return arrayAt(&csv->rows, index);
}

char *csvGetHeader(Csv *csv, size_t index)
{
  return arrayAt(&csv->headers, index);
}

char *csvGetItem(Csv *csv, size_t row, size_t col)
{
  return arrayAt(csvGetRow(csv, row), col);
}

void csvAppendRow(Csv *csv, Array row)
{
  arrayAppend(&csv->rows, &row);
}