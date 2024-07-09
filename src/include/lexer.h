#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <stdbool.h>

typedef struct LEXER_STRUCT
{
  char currentChar, *content;
  unsigned int currentIndex;
} Lexer;

Lexer *newLexer(char *content);

Token *nextToken(Lexer *lexer);

Token *collectValue(Lexer *lexer);

void advance(Lexer *lexer);

char *currentCharAsString(Lexer *lexer);

bool hasReachedEof(Lexer *lexer);

bool isSeparator(char c);

#endif