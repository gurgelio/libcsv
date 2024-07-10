#include "include/libcsv.h"
#include "parsers/include/csv.h"
#include "include/io.h"
#include <stdio.h>

void processCsv(ConstStr csv, ConstStr selectedRows, ConstStr rowFilterDefinitions)
{
  Lexer lexer = newLexer(csv);
  unsigned int numberOfTokens;
  Token *tokens = getTokens(lexer, &numberOfTokens);
  CsvParser parser = newCsvParser(tokens, numberOfTokens);

  Csv parsedCsv = parseCsv(parser);
  printf("%s", csvToString(parsedCsv));
}

void processCsvFile(ConstStr csvFilePath, ConstStr selectedRows, ConstStr rowFilterDefinitions)
{
  Str csv = getFileContents(csvFilePath);
  return processCsv(csv, selectedRows, rowFilterDefinitions);
}
