#include "include/condition.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static inline Operator toOperator(char *operator);

Condition conditionNew(char *header, char *operator, char * value)
{
  Operator op = toOperator(operator);
  if (op == OPERATOR_ILLEGAL)
  {
    fprintf(stderr, "Invalid filter: '%s%s%s'\n", header, operator, value);
    exit(1);
  }

  return (Condition){
      .header = header,
      .operator= op,
      .value = value};
}

bool testCondition(Condition *condition, char *value)
{
  switch (condition->operator)
  {
  case OPERATOR_EQUALS:
    return strcmp(value, condition->value) == 0;
  case OPERATOR_GREATER_THAN:
    return strcmp(value, condition->value) > 0;
  case OPERATOR_GREATER_THAN_OR_EQUALS:
    return strcmp(value, condition->value) >= 0;
  case OPERATOR_LESS_THAN:
    return strcmp(value, condition->value) < 0;
  case OPERATOR_LESS_THAN_OR_EQUALS:
    return strcmp(value, condition->value) <= 0;
  case OPERATOR_NOT_EQUALS:
    return strcmp(value, condition->value) != 0;
  default:
    fprintf(stderr, "Unknown operator %d\n", condition->operator);
    exit(1);
  }
}

static inline Operator toOperator(char *operator)
{
  if (strcmp(operator, "=") == 0)
    return OPERATOR_EQUALS;
  if (strcmp(operator, "!=") == 0)
    return OPERATOR_NOT_EQUALS;
  if (strcmp(operator, "<") == 0)
    return OPERATOR_LESS_THAN;
  if (strcmp(operator, "<=") == 0)
    return OPERATOR_LESS_THAN_OR_EQUALS;
  if (strcmp(operator, ">") == 0)
    return OPERATOR_GREATER_THAN;
  if (strcmp(operator, ">=") == 0)
    return OPERATOR_GREATER_THAN_OR_EQUALS;
  return OPERATOR_ILLEGAL;
}