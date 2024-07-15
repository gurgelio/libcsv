#ifndef CSV_H
#define CSV_H

#include "array.h"

typedef struct
{
  Array headers, rows;
} Csv;

Csv csvNew();

char *csvToString(Csv *csv);

void csvRemoveRow(Csv *csv, int index);

char *csvGetHeader(Csv *csv, int index);

char *csvGetItem(Csv *csv, int row, int col);

void csvRemoveColumn(Csv *csv, int index);

void csvAppendRow(Csv *csv, Array row);

#endif