#ifndef CSV_H
#define CSV_H
#include "../../include/token.h"
#include "../../include/str.h"
#include <stdbool.h>

typedef struct CSV_PARSER_STRUCT
{
  Token *tokens, currentToken;
  unsigned int numberOfTokens, currentIndex;
} *CsvParser;

typedef struct CSV_STRUCT
{
  Str *headers, **rows;
  unsigned int numberOfHeaders, numberOfRows;
} *Csv;

CsvParser newCsvParser(Token *tokens, unsigned int numberOfTokens);

Str csvToString(Csv csv);

Csv parseCsv(CsvParser parser);

Str *parseRow(CsvParser parser, unsigned int *rowSize);

void eat(CsvParser parser, TokenType type);

bool eatIf(CsvParser parser, TokenType type);

#endif