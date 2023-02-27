#include <stdio.h>
#include <assert.h>
#include "foo.h"

int main() {
  printf("main1\n");
  foo();

  int a[1024];
  int n = 10240;
  // a[n] = 1;
  assert(0);
}
