#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char* argv[]) {

  pid_t status;

  status = fork();

  if (status == 0) { // Codigo del Hijo
    return 1;
  }
  else { // Padre
    /* int retValue; */
    /* waitpid(status, &retValue, 0); */
    /* printf("My son end with status: %d\n", WEXITSTATUS(retValue)); */
  }


  return 0;
}
			  
