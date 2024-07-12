#ifndef CSV_PARSER_H
#define CSV_PARSER_H
#include "token.h"
#include "csv.h"
#include <stdbool.h>

typedef struct
{
  Token *currentToken;
  Array tokens;
  unsigned int currentIndex;
} CsvParser;

CsvParser csvParserNew(Array tokens);

Csv parseCsv(CsvParser *parser);

Array parseRow(CsvParser *parser);

void eat(CsvParser *parser, TokenType type);

bool eatIf(CsvParser *parser, TokenType type);

#endif