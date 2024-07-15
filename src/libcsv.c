#include "include/libcsv.h"
#include "include/parser.h"
#include "include/filterSelections.h"
#include "include/filterConditions.h"
#include "include/io.h"
#include <stdio.h>

void processCsv(const char *csv, const char *selectedRows, const char *rowFilterDefinitions)
{
  Csv parsedCsv = parseCsv(csv);
  Array conditions = parseConditions(rowFilterDefinitions);
  Array selections = parseSelections(selectedRows);

  filterConditions(&parsedCsv, &conditions);
  filterSelections(&parsedCsv, &selections);

  printf("%s\n", csvToString(&parsedCsv));
}

void processCsvFile(const char *csvFilePath, const char *selectedRows, const char *rowFilterDefinitions)
{
  return processCsv(getFileContents(csvFilePath), selectedRows, rowFilterDefinitions);
}
