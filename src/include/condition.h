#ifndef CONDITION_H
#define CONDITION_H

#include <stdbool.h>

typedef enum
{
  OPERATOR_GREATER_THAN,
  OPERATOR_LESS_THAN,
  OPERATOR_EQUALS,
  OPERATOR_NOT_EQUALS,
  OPERATOR_LESS_THAN_OR_EQUALS,
  OPERATOR_GREATER_THAN_OR_EQUALS,
  OPERATOR_ILLEGAL = -1
} Operator;

typedef struct
{
  char *header, *value;
  Operator operator;
} Condition;

/**
 * Creates a new Condition struct
 *
 * @param header The string of the header
 * @param operator The string of the operator
 * @param value The value to compare with the rows
 *
 * @returns A dynamic condition to be tested against value of the csv
 */
Condition conditionNew(char *header, char *operator, char * value);

/**
 * Tests the condition against the given value
 *
 * @param condition The condition to apply
 * @param value The value to compare
 *
 * @returns True if the value passes the condition, False otherwise
 */
bool testCondition(Condition *condition, char *value);
#endif