#ifndef TOKEN_H
#define TOKEN_H

#include "str.h"

typedef enum TOKEN_TYPE_ENUM
{
  TOKEN_EOF,
  TOKEN_COMMA,
  TOKEN_NEWLINE,
  TOKEN_GREATER_THAN,
  TOKEN_LESS_THAN,
  TOKEN_EQUALS,
  TOKEN_VALUE,
} TokenType;

typedef struct
{
  Str value;
  TokenType type;
} Token;

Token tokenNew(TokenType type, Str value);

Str tokenToString(Token *token);

Str tokenTypeToString(TokenType type);

#endif