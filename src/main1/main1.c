#include <stdio.h>
#include "foo.h"
#include <assert.h>

int main()
{
  printf("main1\n");
  foo();
  assert(0);
}
