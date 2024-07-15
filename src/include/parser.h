#ifndef CSV_PARSER_H
#define CSV_PARSER_H
#include "token.h"
#include "csv.h"
#include <stdbool.h>

/**
 * Parses a csv string into a Csv
 *
 * @param content A string with a valid csv
 *
 * @returns a Csv struct
 */
Csv parseCsv(const char *content);

/**
 * Parses a list of selections
 *
 * @param selectedRows A string with selections, separated by ','
 *
 * @returns An array of strings
 */
Array parseSelections(const char *selectedRows);

/**
 * Parses a list of conditions (HeaderName{Op}Value)
 * Where Op is an operator, accepted operators are: =,!=,<,<=,>,>=
 * Value is always read as a string
 *
 * @param rowFilterDefinitions A string with conditions (HeaderName{Op}{Value}), separated by '\\n'
 *
 * @returns An array of Condition
 */
Array parseConditions(const char *rowFilterDefinitions);

#endif