#include "include/filterConditions.h"
#include "include/condition.h"
#include <stdio.h>
#include <stdlib.h>

void filterConditions(Csv *csv, Array *conditions)
{
  for (int c = 0; c < conditions->size; c++)
  {
    Condition *condition = arrayAt(conditions, c);
    int headerIndex = arrayFindString(&csv->headers, condition->header);

    if (headerIndex == -1)
    {
      fprintf(stderr, "Header '%s' not found in CSV file/string\n", condition->header);
      exit(1);
    }

    for (int row = csv->rows.size - 1; row >= 0; row--)
    {
      if (!testCondition(condition, csvGetItem(csv, row, headerIndex)))
        csvRemoveRow(csv, row);
    }
  }
}
