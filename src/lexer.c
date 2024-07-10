#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/lexer.h"

Lexer lexerNew(ConstStr content)
{
  return (Lexer){
      .content = content,
      .currentChar = content[0],
      .currentIndex = 0};
}

Token *lexerGetTokens(Lexer *lexer, unsigned int *numberOfTokens)
{
  *numberOfTokens = 0;
  Token *tokens = calloc(1, sizeof(Token)), token = lexerNextToken(lexer);
  while (token.type != TOKEN_EOF)
  {
    *numberOfTokens += 1;
    tokens = realloc(tokens, (*numberOfTokens) * sizeof(Token));
    tokens[*numberOfTokens - 1] = token;
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
    return tokenNew(TOKEN_EQUALS, "=");
  case '<':
    advance(lexer);
    return tokenNew(TOKEN_LESS_THAN, "<");
  case '>':
    advance(lexer);
    return tokenNew(TOKEN_GREATER_THAN, ">");
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
  Str value = calloc(1, sizeof(char));
  value[0] = '\0';

  while (!isSeparator(lexer->currentChar))
  {
    Str s = currentCharAsString(lexer);
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

Str currentCharAsString(Lexer *lexer)
{
  Str str = calloc(2, sizeof(char));
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