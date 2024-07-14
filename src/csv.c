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
    rowStr = arrayToString(csvGetRow(csv, index));

    acc = realloc(acc, (strlen(acc) + strlen(rowStr) + 1) * sizeof(char));
    strcat(acc, "\n");
    strcat(acc, rowStr);
  }
  return acc;
}

void csvRemoveRow(Csv *csv, int index)
{
  arrayRemove(&csv->rows, index);
}

Array *csvGetRow(Csv *csv, int index)
{
  return arrayAt(&csv->rows, index);
}

char *csvGetHeader(Csv *csv, int index)
{
  return arrayAt(&csv->headers, index);
}

char *csvGetItem(Csv *csv, int row, int col)
{
  return arrayAt(csvGetRow(csv, row), col);
}

void csvRemoveColumn(Csv *csv, int index)
{
  arrayRemove(&csv->headers, index);
  for (int row = 0; row < csv->rows.size; row++)
  {
    arrayRemove(arrayAt(&csv->rows, row), index);
  }
}

void csvAppendRow(Csv *csv, Array row)
{
  arrayAppend(&csv->rows, &row);
}