#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
char buffer[BUFFER_SIZE];

void fill_buffer(char *buffer, unsigned int size);

int main(int argc, char* argv[], char * env[]) {
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
    
    for (int i = 0; i < 10; i++) {
      fill_buffer(buffer, BUFFER_SIZE);
      write(tuberia[1], buffer, BUFFER_SIZE);
    }
    close(tuberia[1]);

    int estado;
    waitpid(id_hijo, &estado, 0);
  }

  return EXIT_SUCCESS;
}
  

void fill_buffer(char *buffer, unsigned int size) {
  char c = 'A';
  for (unsigned int i = 0; i < size; i++) {
    buffer[i] = c;
    c++;
    if (c > 'z') {
      c = 'A';
    }
  }
}
