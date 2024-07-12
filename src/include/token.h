#ifndef TOKEN_H
#define TOKEN_H

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
  char *value;
  TokenType type;
} Token;

Token tokenNew(TokenType type, char *value);

char *tokenToString(Token *token);

char *tokenTypeToString(TokenType type);

#endif