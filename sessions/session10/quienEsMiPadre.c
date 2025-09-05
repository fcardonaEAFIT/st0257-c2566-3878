#include <stdio.h>
#include <unistd.h>

int
main() {
  printf("Yo soy: %d y mi padre es: %d\n", getpid(),
	 getppid());

  return 0;
}
