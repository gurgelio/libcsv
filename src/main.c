#include "include/main.h"
#include "include/lexer.h"
#include <stdio.h>

void processCsv(const char csv[], const char selectedRows[], const char rowFilterDefinitions[])
{
}

void processCsvFile(const char csvFilePath[], const char selectedRows[], const char rowFilterDefinitions[])
{
}

int main(int argc, char *argv[])
{
  Lexer *lexer = newLexer(
      "col1,col2,col3\n"
      "1,2,3\n"
      "4,5,6\n"
      "7,8,9");
  Token *token = nextToken(lexer);

  while (token->type != TOKEN_EOF)
  {
    printf("TOKEN(%d, '%s')\n", token->type, token->value);
    token = nextToken(lexer);
  }
}
