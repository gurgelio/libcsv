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

  sprintf(s, "Token(%s, '%s')", tokenTypeToString(token->type), token->value);
  return s;
}

char *tokenTypeToString(TokenType type)
{
  char *s = NULL;
  switch (type)
  {
  case TOKEN_COMMA:
    return ",";
  case TOKEN_OPERATOR:
    return "OPERATOR";
  case TOKEN_NEWLINE:
    return "\\n";
  case TOKEN_VALUE:
    return "VALUE";
  default:
    s = malloc(100 * sizeof(char));
    sprintf(s, "%d", type);
    return s;
  }
}