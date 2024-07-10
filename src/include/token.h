#ifndef TOKEN_H
#define TOKEN_H

#include "str.h"

typedef enum TOKEN_TYPE_ENUM
{
  TOKEN_COMMA,
  TOKEN_NEWLINE,
  TOKEN_GREATER_THAN,
  TOKEN_LESS_THAN,
  TOKEN_EQUALS,
  TOKEN_VALUE,
  TOKEN_EOF
} TokenType;

typedef struct TOKEN_STRUCT
{
  Str value;
  TokenType type;
} *Token;

Token newToken(TokenType type, Str value);

Str tokenToString(Token token);

Str tokenTypeToString(TokenType type);

#endif