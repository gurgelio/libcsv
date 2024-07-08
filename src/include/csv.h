#ifndef CSV_H
#define CSV_H

typedef struct CSV_STRUCT
{
  char **header;
  char **rows;
} Csv;

Csv *parseCsv(char *csvStr);
#endif
