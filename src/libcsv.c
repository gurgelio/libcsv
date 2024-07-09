#include "include/libcsv.h"
#include <stdio.h>

void processCsv(const char csv[], const char selectedRows[], const char rowFilterDefinitions[])
{
  fprintf(stderr, "%s, %s, %s\n", csv, selectedRows, rowFilterDefinitions);
}

void processCsvFile(const char csvFilePath[], const char selectedRows[], const char rowFilterDefinitions[])
{
  fprintf(stderr, "%s, %s, %s\n", csvFilePath, selectedRows, rowFilterDefinitions);
}
