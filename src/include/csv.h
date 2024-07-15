#ifndef CSV_H
#define CSV_H

#include "array.h"

typedef struct
{
  Array headers, rows;
} Csv;

/**
 * Creates a new Csv
 *
 * @returns an empty Csv
 */
Csv csvNew();

/**
 * Writes the Csv to a string
 *
 * @param csv The Csv to be printed
 *
 * @returns The Csv as a String
 */
char *csvToString(Csv *csv);

/**
 * Removes a column from the header and all rows
 *
 * @param csv The csv to be changed
 * @param index The index of the column to be removed
 *
 * @returns void
 */
void csvRemoveColumn(Csv *csv, int index);

#endif