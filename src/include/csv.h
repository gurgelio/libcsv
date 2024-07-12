#ifndef CSV_H
#define CSV_H

#include "array.h"

typedef struct
{
  Array headers, rows;
} Csv;

Csv csvNew();

char *csvToString(Csv *csv);

Array *csvGetRow(Csv *csv, size_t index);

char *csvGetHeader(Csv *csv, size_t index);

char *csvGetItem(Csv *csv, size_t row, size_t col);

void csvAppendRow(Csv *csv, Array row);

#endif