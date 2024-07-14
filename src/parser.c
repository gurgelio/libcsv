#include "include/parser.h"
#include "include/lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CsvParser csvParserNew(Array tokens)
{
  return (CsvParser){
      .tokens = tokens,
      .currentIndex = 0,
      .currentToken = tokens.size > 0 ? arrayAt(&tokens, 0) : NULL};
}

Csv parseCsv(const char *content)
{
  CsvParser parser = csvParserNew(lex(content));
  Csv csv = csvNew();

  csv.headers = parseRow(&parser);

  Array row;
  while (parser.currentToken != NULL && eatIf(&parser, TOKEN_NEWLINE))
  {
    row = parseRow(&parser);

    if (row.size == 0)
      continue;
    if (row.size != csv.headers.size)
    {
      fprintf(stderr, "Inconsistent columns! Expected %d columns, but got %d\n", csv.headers.size, row.size);
      exit(1);
    }

    csvAppendRow(&csv, row);
  }

  return csv;
}

Array parseSelections(const char *selectedRows)
{
  CsvParser parser = csvParserNew(lex(selectedRows));

  return parseRow(&parser);
}

Array parseRow(CsvParser *parser)
{
  Array row = arrayNew(sizeof(char *));
  while (parser->currentToken != NULL && parser->currentToken->type != TOKEN_NEWLINE)
  {
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
  if (parser->currentToken == NULL)
    return false;
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
