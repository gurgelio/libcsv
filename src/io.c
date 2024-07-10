#include "include/io.h"
#include <stdlib.h>
#include <stdio.h>
#include "include/str.h"

Str getFileContents(ConstStr filepath)
{
  Str buffer = 0;
  long length;

  FILE *f = fopen(filepath, "rb");

  if (f)
  {
    fseek(f, 0, SEEK_END);
    length = ftell(f);
    fseek(f, 0, SEEK_SET);

    buffer = calloc(length, length);

    if (buffer)
      fread(buffer, 1, length, f);

    fclose(f);
    return buffer;
  }

  printf("Error reading file %s\n", filepath);
  exit(2);
}