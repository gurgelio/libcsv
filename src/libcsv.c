#include "include/libcsv.h"
#include "include/csvParser.h"
#include "include/io.h"
#include <stdio.h>

void processCsv(ConstStr csv, ConstStr selectedRows, ConstStr rowFilterDefinitions)
{
  fprintf(stderr, "processCsv('%s', '%s', '%s')\n", csv, selectedRows, rowFilterDefinitions);
  Lexer lexer = lexerNew(csv);
  unsigned int numberOfTokens;
  Token *tokens = lexerGetTokens(&lexer, &numberOfTokens);
  CsvParser parser = csvParserNew(tokens, numberOfTokens);
  Csv parsedCsv = parseCsv(&parser);
  fprintf(stderr, "headers: %s\n", arrayToString(&parsedCsv.headers));
  fprintf(stderr, "%s\n", csvToString(&parsedCsv));
  printf("%s", csvToString(&parsedCsv));
}

void processCsvFile(ConstStr csvFilePath, ConstStr selectedRows, ConstStr rowFilterDefinitions)
{
  Str csv = getFileContents(csvFilePath);
  return processCsv(csv, selectedRows, rowFilterDefinitions);
}

int main()
{
  Str file = getFileContents("data.csv");
  processCsv(file, "", "");

  return 0;
}
