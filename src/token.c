#include "include/token.h"
#include <stdlib.h>

Token *newToken(TokenType type, char *value)
{
  Token *t = malloc(sizeof(struct TOKEN_STRUCT));
  t->type = type;
  t->value = value;
  return t;
}