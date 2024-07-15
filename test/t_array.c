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
    tstclock("Check counting time")
    {
      volatile int b = 1;
      // Code to analyze...
      for (int a = 1; a < 100; a++)
        b = a + b;
    }
  }

  tstcase("arrayToString")
  {
  }

  tstcase("arrayAppend")
  {
  }

  tstcase("arrayRemove")
  {
  }

  tstcase("arrayFree")
  {
  }

  tstcase("arrayAt")
  {
  }
}