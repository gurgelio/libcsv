#include "include/parser.h"
#include "include/lexer.h"
#include "include/condition.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Parser parserNew(Array tokens)
{
  return (Parser){
      .tokens = tokens,
      .currentIndex = 0,
      .currentToken = tokens.size > 0 ? arrayAt(&tokens, 0) : NULL};
}

Csv parseCsv(const char *content)
{
  Parser parser = parserNew(lex(content));
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
  Parser parser = parserNew(lex(selectedRows));

  return parseRow(&parser);
}

Array parseConditions(const char *rowFilterDefinitions)
{
  Parser parser = parserNew(lex(rowFilterDefinitions));
  Array conditions = arrayNew(sizeof(Condition));

  while (parser.currentToken != NULL)
  {
    char *header = eat(&parser, TOKEN_VALUE)->value, *operator= eat(&parser, TOKEN_OPERATOR)->value, *value = eat(&parser, TOKEN_VALUE)->value;
    Condition condition = conditionNew(header, operator, value);
    arrayAppend(&conditions, &condition);

    if (!eatIf(&parser, TOKEN_NEWLINE))
    {
      break;
    }
  }
  return conditions;
}

Array parseRow(Parser *parser)
{
  Array row = arrayNew(sizeof(char *));
  while (parser->currentToken != NULL && parser->currentToken->type != TOKEN_NEWLINE)
  {
    arrayAppend(&row, eat(parser, TOKEN_VALUE)->value);
    if (!eatIf(parser, TOKEN_COMMA))
      break;
  }

  return row;
}

Token *eat(Parser *parser, TokenType type)
{
  Token *token = parser->currentToken;
  if (!eatIf(parser, type))
  {
    fprintf(stderr, "Unexpected Token: expected %s, got %s\n", tokenTypeToString(type), tokenToString(parser->currentToken));
    exit(1);
  }
  return token;
}

bool eatIf(Parser *parser, TokenType type)
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
