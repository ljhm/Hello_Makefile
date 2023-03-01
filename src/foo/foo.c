#include <stdio.h>
#include <sanitizer/lsan_interface.h>
#include <signal.h>
#include <assert.h>
#include "foo.h"

void handlerCont(int signum) {
  printf("SIGCONT %d\n", signum);
#ifndef NDEBUG
  __lsan_do_recoverable_leak_check();
#endif
}

void foo() {
  signal(SIGCONT, handlerCont); // kill -CONT <pid>
  printf("foo\n");

  int a[1024];
  int n = 10240;
  // a[n] = 1;

}
