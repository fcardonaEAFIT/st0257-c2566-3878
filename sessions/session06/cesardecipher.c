#include <stdio.h>

int
main(int argc, char *argv[]) {

  int c;

  while ((c = getchar()) != EOF) {
    c += (-5);
    putchar(c);
  }

  return 0;
}
