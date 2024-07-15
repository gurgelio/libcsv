#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "include/token.h"
#include "include/lexer.h"

typedef struct
{
  char currentChar;
  const char *content;
  unsigned int currentIndex;
} Lexer;

static inline Token lexerNextToken(Lexer *lexer);
static inline Token collectValue(Lexer *lexer);
static inline void advance(Lexer *lexer);
static inline char *currentCharAsString(Lexer *lexer);
static inline bool isSeparator(char c);
static inline bool hasReachedEof(Lexer *lexer);

Array lex(const char *content)
{
  Lexer lexer = (Lexer){
      .content = content,
      .currentChar = content[0],
      .currentIndex = 0};

  Array tokens = arrayNew(sizeof(Token));
  Token token = lexerNextToken(&lexer);
  while (token.type != TOKEN_EOF)
  {
    arrayAppend(&tokens, &token);
    token = lexerNextToken(&lexer);
  }
  return tokens;
}

static inline Token lexerNextToken(Lexer *lexer)
{
  switch (lexer->currentChar)
  {
  case '!':
    advance(lexer);
    if (lexer->currentChar != '=')
    {
      fprintf(stderr, "Illegal char! expected '=' but got %c", lexer->currentChar);
      exit(1);
    }
    advance(lexer);
    return tokenNew(TOKEN_OPERATOR, "!=");
  case '=':
    advance(lexer);
    return tokenNew(TOKEN_OPERATOR, "=");
  case '<':
    advance(lexer);
    if (lexer->currentChar == '=')
    {
      advance(lexer);
      return tokenNew(TOKEN_OPERATOR, "<=");
    }
    return tokenNew(TOKEN_OPERATOR, "<");
  case '>':
    advance(lexer);
    if (lexer->currentChar == '=')
    {
      advance(lexer);
      return tokenNew(TOKEN_OPERATOR, ">=");
    }
    return tokenNew(TOKEN_OPERATOR, ">");
  case ',':
    advance(lexer);
    return tokenNew(TOKEN_COMMA, ",");
  case '\n':
    advance(lexer);
    return tokenNew(TOKEN_NEWLINE, "\n");
  case 0:
    advance(lexer);
    return tokenNew(TOKEN_EOF, "");
  default:
    return collectValue(lexer);
  }
}

static inline Token collectValue(Lexer *lexer)
{
  char *value = calloc(1, sizeof(char));
  value[0] = '\0';

  while (!isSeparator(lexer->currentChar))
  {
    char *s = currentCharAsString(lexer);
    value = realloc(value, (strlen(value) + strlen(s)) * sizeof(char));
    strcat(value, s);
    advance(lexer);
  }

  return tokenNew(TOKEN_VALUE, value);
}

static inline void advance(Lexer *lexer)
{
  lexer->currentIndex += 1;
  if (hasReachedEof(lexer))
  {
    lexer->currentChar = '\0';
    return;
  }

  lexer->currentChar = lexer->content[lexer->currentIndex];
}

static inline char *currentCharAsString(Lexer *lexer)
{
  char *str = calloc(2, sizeof(char));
  if (str == NULL)
    fprintf(stderr, "failed to alloc\n");
  str[0] = lexer->currentChar;
  str[1] = '\0';

  return str;
}

static inline bool isSeparator(char c)
{
  return c == ',' || c == '<' || c == '>' || c == '=' || c == '!' || c == '\n' || c == '\0';
}

static inline bool hasReachedEof(Lexer *lexer)
{
  return lexer->currentIndex >= strlen(lexer->content);
}
