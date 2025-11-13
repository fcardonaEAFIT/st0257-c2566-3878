#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include "tuberia_info.h"

#define BUFFER_SIZE 1024
char buffer[BUFFER_SIZE];

void fill_buffer(char *buffer, unsigned int size);

int main(int argc, char* argv[], char * env[]) {

  PTUBERIA_INFO ptuberia_info = lanzar_catl();
  
  for (int i = 0; i < 10; i++) {
    fill_buffer(buffer, BUFFER_SIZE);
    write(ptuberia_info->escribir, buffer, BUFFER_SIZE);
  }
  close(ptuberia_info->escribir);
  
  int estado;
  waitpid(ptuberia_info->hijo, &estado, 0);

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
