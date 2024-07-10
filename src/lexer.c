#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/lexer.h"

Lexer newLexer(ConstStr content)
{
  Lexer l = malloc(sizeof(struct LEXER_STRUCT));
  l->content = content;
  l->currentChar = content[0];
  l->currentIndex = 0;
  return l;
}

Token *getTokens(Lexer lexer, unsigned int *numberOfTokens)
{
  *numberOfTokens = 0;
  Token *tokens = calloc(1, sizeof(struct TOKEN_STRUCT)), token = nextToken(lexer);
  while (token->type != TOKEN_EOF)
  {
    tokens = realloc(tokens, ++(*numberOfTokens) * sizeof(struct TOKEN_STRUCT));
    tokens[*numberOfTokens - 1] = token;
    token = nextToken(lexer);
  }
  return tokens;
}

Token nextToken(Lexer lexer)
{
  switch (lexer->currentChar)
  {
  case '=':
    advance(lexer);
    return newToken(TOKEN_EQUALS, "=");
  case '<':
    advance(lexer);
    return newToken(TOKEN_LESS_THAN, "<");
  case '>':
    advance(lexer);
    return newToken(TOKEN_GREATER_THAN, ">");
  case ',':
    advance(lexer);
    return newToken(TOKEN_COMMA, ",");
  case '\n':
    advance(lexer);
    return newToken(TOKEN_NEWLINE, "\n");
  case 0:
    advance(lexer);
    return newToken(TOKEN_EOF, "");
  default:
    return collectValue(lexer);
  }
}

Token collectValue(Lexer lexer)
{
  Str value = calloc(1, sizeof(char));
  value[0] = '\0';

  while (!isSeparator(lexer->currentChar))
  {
    Str s = currentCharAsString(lexer);
    value = realloc(value, (strlen(value) + strlen(s)) * sizeof(char));
    strcat(value, s);
    advance(lexer);
  }

  return newToken(TOKEN_VALUE, value);
}

void advance(Lexer lexer)
{
  lexer->currentIndex++;
  if (hasReachedEof(lexer))
  {
    lexer->currentChar = '\0';
    return;
  }

  lexer->currentChar = lexer->content[lexer->currentIndex];
}

Str currentCharAsString(Lexer lexer)
{
  Str str = calloc(2, sizeof(char));
  str[0] = lexer->currentChar;
  str[1] = '\0';

  return str;
}

bool isSeparator(char c)
{
  return c == ',' || c == '<' || c == '>' || c == '=' || c == '!' || c == '\n' || c == '\0';
}

bool hasReachedEof(Lexer lexer)
{
  return lexer->currentIndex >= strlen(lexer->content);
}