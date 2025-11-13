#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include "tuberia_info.h"

PTUBERIA_INFO lanzar_catl(void) {
  int tuberia[2];

  pipe(tuberia);
  
  pid_t id_hijo;
  
  if ((id_hijo = fork()) == 0) { // Hijo
    // close(tuberia[1]);
    dup2(tuberia[0], 0);
    close(tuberia[1]);
    close(tuberia[0]);
    execl("./catl", "catl", NULL);
    _exit(1);
  }
  else { // Padre
    close(tuberia[0]);
  }

  PTUBERIA_INFO pTuberia = malloc(sizeof(struct Tuberia_Info));
  pTuberia->hijo = id_hijo;
  pTuberia->escribir = tuberia[1];

  return pTuberia;
}
