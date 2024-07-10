#include "include/csv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CsvParser newCsvParser(Token *tokens, unsigned int numberOfTokens)
{
  CsvParser parser = malloc(sizeof(struct CSV_PARSER_STRUCT));
  parser->numberOfTokens = numberOfTokens;
  parser->tokens = tokens;
  parser->currentIndex = 0;
  parser->currentToken = tokens[0];
  return parser;
}

Csv parseCsv(CsvParser parser)
{
  Csv csv = malloc(sizeof(struct CSV_STRUCT));
  csv->headers = parseRow(parser, &csv->numberOfHeaders);

  csv->numberOfRows = 0;
  csv->rows = calloc(1, sizeof(Str *));
  unsigned int rowSize;
  while (!eatIf(parser, TOKEN_EOF) && eatIf(parser, TOKEN_NEWLINE))
  {
    csv->rows = realloc(csv->rows, ++csv->numberOfRows * sizeof(Str *));
    csv->rows[csv->numberOfRows - 1] = parseRow(parser, &rowSize);
    if (rowSize != csv->numberOfHeaders)
    {
      if (rowSize == 0)
        break;
      fprintf(stderr, "Inconsistent columns! Expected %d columns, but got %d", csv->numberOfHeaders, rowSize);
      exit(1);
    }
  }

  return csv;
}

Str csvToString(Csv csv)
{
  Str str = calloc(1, sizeof(char));

  fprintf(stderr, "PRE HEADERS\n");
  for (unsigned int index = 0; index < csv->numberOfHeaders; index++)
  {
    str = realloc(str, (strlen(str) + strlen(csv->headers[index]) + 1) * sizeof(char));
    strcat(str, csv->headers[index]);
    if (index < csv->numberOfHeaders - 1)
      strcat(str, ",");
  }
  fprintf(stderr, "POST HEADERS\n");
  for (unsigned int row = 0; row < csv->numberOfRows; row++)
  {
    strcat(str, "\n");
    for (unsigned int col = 0; col < csv->numberOfHeaders; col++)
    {
      str = realloc(str, (strlen(str) + strlen(csv->rows[row][col]) + 1) * sizeof(char));
      strcat(str, csv->rows[row][col]);
      if (col < csv->numberOfHeaders - 1)
        strcat(str, ",");
    }
  }
  return str;
}

Str *parseRow(CsvParser parser, unsigned int *rowSize)
{
  *rowSize = 0;
  Str *row = calloc(1, sizeof(Str));
  while (parser->currentToken->type != TOKEN_NEWLINE && parser->currentToken->type != TOKEN_EOF)
  {
    // TODO: talvez adicionar casos para cuidar de caracteres especiais como header
    row = realloc(row, ++(*rowSize) * sizeof(Str));
    row[*rowSize - 1] = parser->currentToken->value;
    eat(parser, TOKEN_VALUE);
    if (!eatIf(parser, TOKEN_COMMA))
    {
      break;
    }
  }

  return row;
}

void eat(CsvParser parser, TokenType type)
{
  if (!eatIf(parser, type))
  {
    fprintf(stderr, "Unexpected Token: expected %s, got %s", tokenTypeToString(type), tokenToString(parser->currentToken));
    exit(1);
  }
}

bool eatIf(CsvParser parser, TokenType type)
{
  if (parser->currentToken->type != type)
    return false;

  parser->currentIndex++;
  if (parser->currentIndex < parser->numberOfTokens)
  {
    parser->currentToken = parser->tokens[parser->currentIndex];
  }
  else
  {
    parser->currentToken = newToken(TOKEN_EOF, "");
  }
  return true;
}