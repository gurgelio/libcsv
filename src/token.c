#include "include/token.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

Token tokenNew(TokenType type, char *value)
{
  return (Token){
      .type = type,
      .value = value};
}

char *tokenToString(Token *token)
{
  char *s = malloc(100 * sizeof(char));
  if (s == NULL)
    fprintf(stderr, "failed to alloc\n");

  sprintf(s, "Token(%s, '%s')", tokenTypeToString(token->type), token->value);
  return s;
}

char *tokenTypeToString(TokenType type)
{
  switch (type)
  {
  case TOKEN_COMMA:
    return ",";
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
    char *s = malloc(100 * sizeof(char));
    if (s == NULL)
      fprintf(stderr, "failed to alloc\n");
    sprintf(s, "%d", type);
    return s;
  }
}