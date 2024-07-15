#ifndef CSV_PARSER_H
#define CSV_PARSER_H
#include "token.h"
#include "csv.h"
#include <stdbool.h>

Csv parseCsv(const char *content);

Array parseSelections(const char *selectedRows);

Array parseConditions(const char *rowFilterDefinitions);

#endif