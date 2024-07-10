#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <stdbool.h>

typedef struct
{
  char currentChar;
  ConstStr content;
  unsigned int currentIndex;
} Lexer;

Lexer lexerNew(ConstStr content);

Token *lexerGetTokens(Lexer *lexer, unsigned int *numberOfTokens);

Token lexerNextToken(Lexer *lexer);

Token collectValue(Lexer *lexer);

void advance(Lexer *lexer);

Str currentCharAsString(Lexer *lexer);

bool hasReachedEof(Lexer *lexer);

bool isSeparator(char c);

#endif