#include <stdio.h>

int
main(int argc, char* argv[]) {
  int elementos[] = { 1, 3, 9, 0};

  int *px = elementos;
  for (int i = 0; *(px + i) != 0; i++) {
    printf("%d\n", *(px + i));
  }

  return 0;
}
		
