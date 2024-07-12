#include "include/csvParser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CsvParser csvParserNew(Array tokens)
{
  return (CsvParser){
      .tokens = tokens,
      .currentIndex = 0,
      .currentToken = arrayAt(&tokens, 0)};
}

Csv parseCsv(CsvParser *parser)
{
  Csv csv = csvNew();

  csv.headers = parseRow(parser);

  Array row;
  while (parser->currentToken != NULL && eatIf(parser, TOKEN_NEWLINE))
  {
    row = parseRow(parser);

    if (row.size == 0)
      continue;
    if (row.size != csv.headers.size)
    {
      fprintf(stderr, "Inconsistent columns! Expected %ld columns, but got %ld\n", csv.headers.size, row.size);
      exit(1);
    }

    csvAppendRow(&csv, row);
  }

  return csv;
}

Array parseRow(CsvParser *parser)
{
  Array row = arrayNew(sizeof(char *));
  while (parser->currentToken != NULL && parser->currentToken->type != TOKEN_NEWLINE)
  {
    // TODO: talvez adicionar casos para cuidar de caracteres especiais como header
    arrayAppend(&row, parser->currentToken->value);
    eat(parser, TOKEN_VALUE);
    if (!eatIf(parser, TOKEN_COMMA))
    {
      break;
    }
  }

  return row;
}

void eat(CsvParser *parser, TokenType type)
{
  if (!eatIf(parser, type))
  {
    fprintf(stderr, "Unexpected Token: expected %s, got %s\n", tokenTypeToString(type), tokenToString(parser->currentToken));
    exit(1);
  }
}

bool eatIf(CsvParser *parser, TokenType type)
{
  if (parser->currentToken->type != type)
    return false;

  parser->currentIndex++;
  if (parser->currentIndex < parser->tokens.size)
  {
    parser->currentToken = arrayAt(&parser->tokens, parser->currentIndex);
  }
  else
  {
    parser->currentToken = NULL;
  }
  return true;
}
