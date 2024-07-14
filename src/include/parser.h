#ifndef CSV_PARSER_H
#define CSV_PARSER_H
#include "token.h"
#include "csv.h"
#include <stdbool.h>

typedef struct
{
  Token *currentToken;
  Array tokens;
  int currentIndex;
} Parser;

Parser parserNew(Array tokens);

Csv parseCsv(const char *content);

Array parseSelections(const char *selectedRows);

Array parseConditions(const char *rowFilterDefinitions);

Array parseRow(Parser *parser);

Token *eat(Parser *parser, TokenType type);

bool eatIf(Parser *parser, TokenType type);

#endif