#ifndef TOKEN_H
#define TOKEN_H

typedef enum TOKEN_TYPE_ENUM
{
  TOKEN_COMMA,
  TOKEN_NEWLINE,
  TOKEN_GREATER_THAN,
  TOKEN_LESS_THAN,
  TOKEN_LESS_THAN_OR_EQUALs,
  TOKEN_EQUALS,
  TOKEN_NOT_EQUALS,
  TOKEN_VALUE,
  TOKEN_EOF
} TokenType;

typedef struct TOKEN_STRUCT
{
  char *value;
  TokenType type;
} Token;

Token *newToken(TokenType type, char *value);

#endif