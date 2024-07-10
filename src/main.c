#include "include/main.h"
#include <stdio.h>

int main()
{
  Lexer lexer = newLexer(
      "col1,col2,col3\n"
      "1,2,3\n"
      "4,5,6\n"
      "7,8,9");
  Token token = nextToken(lexer);

  while (token->type != TOKEN_EOF)
  {
    printf("TOKEN(%d, '%s')\n", token->type, token->value);
    token = nextToken(lexer);
  }

  return 0;
}
