#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {

  int desp = 5;

  if (argc > 1) {
    desp = atoi(argv[1]);
  }
  else {
    char* stroffset = getenv("CESARCIPHER");
    if (stroffset) {
      desp = atoi(stroffset);
    }
  }
      
		      
  int c;

  while ((c = getchar()) != EOF) {
    c += desp;
    putchar(c);
  }

  return 0;
}
