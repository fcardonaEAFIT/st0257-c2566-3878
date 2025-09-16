#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define N 10
int n = N;

int buffer[N];
int entra = 0, sale = 0, cantidad = 0;
sem_t *mutex, *vacio, *lleno;

void create_semaphores() {
  mutex = sem_open("mutex", 0);
  vacio = sem_open("vacio", 0);
  lleno = sem_open("lleno", 0);
}

void consumidor() {
  int j;
  for (;;) {
    sem_wait(lleno);
    sem_wait(mutex);
    j = buffer[sale];
    sale = (sale + 1) % N;
    printf("hilo id: %d %d\n", getpid(), j);
    sem_post(mutex);
    sem_post(vacio);
  }
}

int
main(void) {
  create_semaphores();

  consumidor();

  return 0;
}
