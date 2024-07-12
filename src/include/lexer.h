#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include "array.h"
#include <stdbool.h>

typedef struct
{
  char currentChar;
  const char *content;
  unsigned int currentIndex;
} Lexer;

Lexer lexerNew(const char *content);

Array lexerGetTokens(Lexer *lexer);

Token lexerNextToken(Lexer *lexer);

Token collectValue(Lexer *lexer);

void advance(Lexer *lexer);

char *currentCharAsString(Lexer *lexer);

bool hasReachedEof(Lexer *lexer);

bool isSeparator(char c);

#endif