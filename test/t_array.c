#include "tst.h"
#include "../src/include/array.h"

tstsuite("Array")
{
  tstcase("arrayNew")
  {
    Array array = arrayNew(sizeof(int));
    tstcheck(array.size == 0);
    tstcheck(array.capacity == 4);
    tstcheck(array.itemSize == sizeof(int));
  }

  tstcase("arrayFindString")
  {
    Array array = arrayNew(sizeof(char *));
    arrayAppend(&array, "Carlos");
    arrayAppend(&array, "Marcos");

    tstcheck(arrayFindString(&array, "Marcos") == 1);
    tstcheck(arrayFindString(&array, "Neymar") == -1);
    tstcheck(arrayFindString(&array, "") == -1);
  }

  tstcase("arrayToString")
  {
    Array array = arrayNew(sizeof(char *));

    tstcheck(strcmp(arrayToString(&array), "") == 0);

    arrayAppend(&array, "Hello");
    arrayAppend(&array, "World");

    tstcheck(strcmp(arrayToString(&array), "Hello,World") == 0)
  }

  tstcase("arrayAppend")
  {
    Array array = arrayNew(sizeof(int));
    int a = 15, b = 25, c = 70;

    arrayAppend(&array, &a);
    arrayAppend(&array, &b);
    arrayAppend(&array, &c);

    tstcheck(arrayAt(&array, 0) != &a, "Should copy values");
    tstcheck(*((int *)arrayAt(&array, 0)) == a);
    tstcheck(*((int *)arrayAt(&array, 1)) == b);
    tstcheck(*((int *)arrayAt(&array, 2)) == c);
  }

  tstcase("arrayRemove")
  {
    Array array = arrayNew(sizeof(int));
    int a = 15, b = 25, c = 70;

    arrayAppend(&array, &a);
    arrayAppend(&array, &b);
    arrayAppend(&array, &c);

    arrayRemove(&array, 1);

        tstcheck(array.size == 2);
  }

  tstcase("arrayAt")
  {
    Array array = arrayNew(sizeof(int));
    int a = 15, b = 25, c = 70;

    arrayAppend(&array, &a);
    arrayAppend(&array, &b);
    arrayAppend(&array, &c);

    tstcheck(*((int *)arrayAt(&array, 0)) == a);
    tstcheck(*((int *)arrayAt(&array, 2)) == c);
  }
}
