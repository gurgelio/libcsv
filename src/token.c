#include "include/token.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

Token newToken(TokenType type, Str value)
{
  Token t = malloc(sizeof(struct TOKEN_STRUCT));
  t->type = type;
  t->value = value;
  return t;
}

Str tokenToString(Token token)
{
  char *s = malloc(100 * sizeof(char));

  sprintf(s, "Token(%s, '%s')", tokenTypeToString(token->type), token->value);
  return s;
}

Str tokenTypeToString(TokenType type)
{
  switch (type)
  {
  case TOKEN_COMMA:
    return ",";
  case TOKEN_EOF:
    return "EOF";
  case TOKEN_EQUALS:
    return "=";
  case TOKEN_GREATER_THAN:
    return ">";
  case TOKEN_LESS_THAN:
    return "<";
  case TOKEN_NEWLINE:
    return "\\n";
  // case TOKEN_NOT_EQUALS:
  //   return "!=";
  case TOKEN_VALUE:
    return "VALUE";
  default:
    char *s = malloc(sizeof(char) * (int)log10(type));

    sprintf(s, "%d", type);
    return s;
  }
}