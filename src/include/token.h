#ifndef TOKEN_H
#define TOKEN_H

typedef enum TOKEN_TYPE_ENUM
{
  TOKEN_EOF,
  TOKEN_COMMA,
  TOKEN_NEWLINE,
  TOKEN_OPERATOR,
  TOKEN_VALUE,
} TokenType;

typedef struct
{
  char *value;
  TokenType type;
} Token;

/**
 * Creates a new Token
 *
 * @param type The type of the new Token
 * @param value The contents of the new Token
 *
 * @returns A Token
 */
Token tokenNew(TokenType type, char *value);

/**
 * Writes the Token to a string
 *
 * @param token The Token to be printed
 *
 * @returns A string that represents it
 */
char *tokenToString(Token *token);

/**
 * Writes a TokenType as a string
 *
 * @param type The type to be printed
 *
 * @returns A readable name for the Type
 */
char *tokenTypeToString(TokenType type);

#endif