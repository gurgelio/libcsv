#include "include/filterSelections.h"
#include <stdio.h>
#include <stdlib.h>

static inline void validateSelections(Csv *csv, Array *selections);

void filterSelections(Csv *csv, Array *selections)
{
  if (selections->size == 0)
    return;

  validateSelections(csv, selections);

  for (int index = csv->headers.size - 1; index >= 0; index--)
  {
    if (arrayFindString(selections, arrayAt(&csv->headers, index)) != -1)
      continue;
    csvRemoveColumn(csv, index);
  }
}

static inline void validateSelections(Csv *csv, Array *selections)
{
  for (int i = 0; i < selections->size; i++)
  {
    if (arrayFindString(&csv->headers, arrayAt(selections, i)) == -1)
    {
      fprintf(stderr, "Header '%s' not found in CSV file/string", (char *)arrayAt(selections, i));
      exit(1);
    }
  }
}