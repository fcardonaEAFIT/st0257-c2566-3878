#include <stdio.h>

int
main() {
  printf("%p\n", main);
  int* p = 0x000000;
  printf("%d\n", *p);
  return 0;
}
