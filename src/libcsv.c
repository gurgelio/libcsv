#include "include/libcsv.h"
#include "include/csvParser.h"
#include "include/io.h"
#include <stdio.h>

void processCsv(const char *csv, const char *selectedRows, const char *rowFilterDefinitions)
{
  Lexer lexer = lexerNew(csv);
  Array tokens = lexerGetTokens(&lexer);
  CsvParser parser = csvParserNew(tokens);
  Csv parsedCsv = parseCsv(&parser);
  printf("%s\n", csvToString(&parsedCsv));
}

void processCsvFile(const char *csvFilePath, const char *selectedRows, const char *rowFilterDefinitions)
{
  char *csv = getFileContents(csvFilePath);
  return processCsv(csv, selectedRows, rowFilterDefinitions);
}

int main()
{
  char *file = getFileContents("data.csv");
  processCsv(file, "", "");

  return 0;
}
