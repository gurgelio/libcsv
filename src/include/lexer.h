#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <stdbool.h>

typedef struct LEXER_STRUCT
{
  char currentChar;
  ConstStr content;
  unsigned int currentIndex;
} *Lexer;

Lexer newLexer(ConstStr content);

Token *getTokens(Lexer lexer, unsigned int *numberOfTokens);

Token nextToken(Lexer lexer);

Token collectValue(Lexer lexer);

void advance(Lexer lexer);

Str currentCharAsString(Lexer lexer);

bool hasReachedEof(Lexer lexer);

bool isSeparator(char c);

#endif