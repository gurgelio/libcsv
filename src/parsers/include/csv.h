#ifndef CSV_H
#define CSV_H
#include "../../include/token.h"

typedef struct CSV_STRUCT
{
  char **headers, **rows;
} Csv;

Csv parseCsv(Token *tokens);

#endif