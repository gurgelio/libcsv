#include "include/csv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Csv csvNew()
{
  Csv csv = (Csv){
      .rows = arrayNew(sizeof(Array)),
      .headers = arrayNew(sizeof(Str))};

  return csv;
}

Str csvToString(Csv *csv)
{
  Str acc = arrayToString(&csv->headers), rowStr;
  fprintf(stderr, "acc: %s\n", acc);

  for (size_t index = 0; index < csv->rows.size; index++)
  {
    rowStr = arrayToString(csvGetRow(csv, index));
    fprintf(stderr, "row: %s\n", rowStr);
    acc = realloc(acc, (strlen(acc) + strlen(rowStr) + 1) * sizeof(char));
    strcat(acc, "\n");
    strcat(acc, rowStr);
  }
  return acc;
}

Array *csvGetRow(Csv *csv, size_t index)
{
  if (index >= csv->rows.size)
  {
    fprintf(stderr, "Index out of bounds: tried to access %d of %s\n", index, csvToString(csv));
    exit(1);
  }
  return arrayAt(&csv->rows, index);
}

Str csvGetHeader(Csv *csv, size_t index)
{
  return arrayAt(&csv->headers, index);
}

Str csvGetItem(Csv *csv, size_t row, size_t col)
{
  return arrayAt(csvGetRow(csv, row), col);
}

void csvAppendRow(Csv *csv, Array *row)
{
  arrayAppend(&csv->rows, row);
}