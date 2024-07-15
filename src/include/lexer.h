#ifndef LEXER_H
#define LEXER_H

#include "array.h"

/**
 * Lexes a string into tokens
 *
 * @param content The string to be lexed
 *
 * @returns An array of Token
 */
Array lex(const char *content);

#endif