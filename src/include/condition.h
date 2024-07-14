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
  OPERATOR_GREATER_THAN_OR_EQUALS
} Operator;

typedef struct
{
  char *header, *value;
  Operator operator;
} Condition;

Condition conditionNew(char *header, char *operator, char * value);

bool testCondition(Condition *condition, char *value);

Operator toOperator(char *operator);
#endif