#ifndef LIBCSV_H
#define LIBCSV_H

#include "lexer.h"

/**
 * Process the CSV data by applying filters and selecting columns.
 *
 * @param csv The CSV data to be processed.
 * @param selectedColumns The columns to be selected from the CSV data.
 * @param rowFilterDefinitions The filters to be applied to the CSV data.
 *
 * @returns void
 */
void processCsv(const char *, const char *, const char *);

/**
 * Process the CSV data by applying filters and selecting columns.
 *
 * @param csvFilePath The file path of the CSV to be processed.
 * @param selectedColumns The columns to be selected from the CSV data.
 * @param rowFilterDefinitions The filters to be applied to the CSV data.
 *
 * @returns void
 */
void processCsvFile(const char *, const char *, const char *);

#endif