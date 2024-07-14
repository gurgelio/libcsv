#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/lexer.h"

Array lex(const char *content)
{
  Lexer lexer = lexerNew(content);
  return lexerGetTokens(&lexer);
}

Lexer lexerNew(const char *content)
{
  return (Lexer){
      .content = content,
      .currentChar = content[0],
      .currentIndex = 0};
}

Array lexerGetTokens(Lexer *lexer)
{
  Array tokens = arrayNew(sizeof(Token));
  Token token = lexerNextToken(lexer);
  while (token.type != TOKEN_EOF)
  {
    arrayAppend(&tokens, &token);
    token = lexerNextToken(lexer);
  }
  return tokens;
}

Token lexerNextToken(Lexer *lexer)
{
  switch (lexer->currentChar)
  {
  case '=':
    advance(lexer);
    return tokenNew(TOKEN_OPERATOR, "=");
  case '<':
    advance(lexer);
    return tokenNew(TOKEN_OPERATOR, "<");
  case '>':
    advance(lexer);
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

Token collectValue(Lexer *lexer)
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

void advance(Lexer *lexer)
{
  lexer->currentIndex += 1;
  if (hasReachedEof(lexer))
  {
    lexer->currentChar = '\0';
    return;
  }

  lexer->currentChar = lexer->content[lexer->currentIndex];
}

char *currentCharAsString(Lexer *lexer)
{
  char *str = calloc(2, sizeof(char));
  if (str == NULL)
    fprintf(stderr, "failed to alloc\n");
  str[0] = lexer->currentChar;
  str[1] = '\0';

  return str;
}

bool isSeparator(char c)
{
  return c == ',' || c == '<' || c == '>' || c == '=' || c == '!' || c == '\n' || c == '\0';
}

bool hasReachedEof(Lexer *lexer)
{
  return lexer->currentIndex >= strlen(lexer->content);
}