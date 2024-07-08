#include "include/lexer.h"
#include <stdlib.h>
#include <stdio.h>

Lexer *newLexer(char *content)
{
  Lexer *l = malloc(sizeof(struct LEXER_STRUCT));
  l->content = content;
  l->currentChar = content[0];
  l->currentIndex = 0;
  return l;
}

Token *nextToken(Lexer *lexer)
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

Token *collectValue(Lexer *lexer)
{
  char *value = calloc(1, sizeof(char));
  value[0] = '\0';

  while (!isSeparator(lexer->currentChar))
  {
    char *s = currentCharAsString(lexer);
    value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
    strcat(value, s);
    advance(lexer);
  }

  return newToken(TOKEN_VALUE, value);
}

void advance(Lexer *lexer)
{
  lexer->currentIndex++;
  if (hasReachedEof(lexer))
  {
    lexer->currentChar = '\0';
    return;
  }

  lexer->currentChar = lexer->content[lexer->currentIndex];
}

char *currentCharAsString(Lexer *lexer)
{
  char *str = calloc(2, sizeof(char));
  str[0] = lexer->currentChar;
  str[1] = '\0';

  return str;
}

bool isSeparator(char c)
{
  return c == ',' || c == '<' || c == '>' || c == '=' || c == '!' || c == '\n' || c == '\0';
}

bool hasReachedEof(Lexer *lexer)
{
  return lexer->currentIndex >= strlen(lexer->content);
}