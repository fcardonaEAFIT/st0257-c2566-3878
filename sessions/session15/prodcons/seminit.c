#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

#define N 10
int n = N;

int buffer[N];
int entra = 0, sale = 0, cantidad = 0;
sem_t mutex, vacio, lleno;

void create_semaphores() {
  sem_open("mutex", O_CREAT | O_EXCL, 0660, 1);
  sem_open("vacio", O_CREAT | O_EXCL, 0660, N);
  sem_open("lleno", O_CREAT | O_EXCL, 0660, 0);
}

int
main(void) {
  create_semaphores();
  return 0;
}
