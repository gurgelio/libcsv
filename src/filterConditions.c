#include "include/filterConditions.h"
#include "include/condition.h"
#include <stdio.h>
#include <stdlib.h>

void filterConditions(Csv *csv, Array *conditions)
{
  for (int c = 0; c < conditions->size; c++)
  {
    Condition *condition = arrayAt(conditions, c);
    int col = arrayFindString(&csv->headers, condition->header);

    if (col == -1)
    {
      fprintf(stderr, "Header '%s' not found in CSV file/string\n", condition->header);
      exit(1);
    }

    for (int row = csv->rows.size - 1; row >= 0; row--)
    {
      if (!testCondition(condition, arrayAt(arrayAt(&csv->rows, row), col)))
        arrayRemove(&csv->rows, row);
    }
  }
}
