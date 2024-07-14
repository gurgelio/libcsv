#include "include/libcsv.h"
#include "include/parser.h"
#include "include/filterSelections.h"
#include "include/io.h"
#include <stdio.h>

void processCsv(const char *csv, const char *selectedRows, const char *rowFilterDefinitions)
{
  Csv parsedCsv = parseCsv(csv);

  Array selections = parseSelections(selectedRows);

  printf("%s\n", csvToString(&parsedCsv));
  filterSelections(&parsedCsv, &selections);
  printf("%s\n", csvToString(&parsedCsv));
}

void processCsvFile(const char *csvFilePath, const char *selectedRows, const char *rowFilterDefinitions)
{
  return processCsv(getFileContents(csvFilePath), selectedRows, rowFilterDefinitions);
}

int main()
{
  char *file = getFileContents("data.csv");

  processCsv(file, "col1,col3,col2", "");

  return 0;
}
