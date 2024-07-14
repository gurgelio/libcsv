#include "include/filterSelections.h"
#include <stdio.h>

void filterSelections(Csv *csv, Array *selections)
{

  // "Header 'header4' not found in CSV file/string"
  if (selections->size == 0)
    return;

  for (int index = csv->headers.size - 1; index >= 0; index--)
  {
    fprintf(stderr, "headers[%d] = %s\n", index, arrayAt(&csv->headers, index));
    if (arrayFindString(selections, arrayAt(&csv->headers, index)) != -1)
      continue;
    fprintf(stderr, "removing column %d\n", index);
    csvRemoveColumn(csv, index);
  }
}