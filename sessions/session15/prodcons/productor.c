#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define N 10
int n = N;

int buffer[N];
int entra = 0, sale = 0, cantidad = 0;
sem_t mutex*, vacio*, lleno*;

void create_semaphores() {
  mutex = sem_open("mutex", 0);
  vacio = sem_open("vacio", 0);
  lleno = sem_open("lleno", 0);
}

void* productor(void) {
  int i = 0;
  for (;;) {
    sem_wait(vacio);
    sem_wait(mutex);
    buffer[entra] = i;
    entra = (entra + 1) % N;
    i += 2;
    cantidad++;
    sem_post(mutex);
    sem_post(lleno);
  }

  return NULL;
}

void* consumidor(void *arg) {
  int idHilo = *((int*) arg);
  int j;
  for (;;) {
    sem_wait(&lleno);
    sem_wait(&mutex);
    j = buffer[sale];
    sale = (sale + 1) % N;
    printf("hilo id: %d %d\n", idHilo, j);
    sem_post(&vacio);
  }
  return NULL;
}

int
main(void) {
  create_semaphores();
  pthread_t hilo_prod, hilo_cons;

  int hilo_id = 0;
  pthread_create(&hilo_prod, NULL, productor, NULL);
  pthread_create(&hilo_cons, NULL, consumidor, (void *) &hilo_id);

  pthread_t hilo_cons2;
  int hilo_id2 = 1;
  pthread_create(&hilo_cons2, NULL, consumidor, (void *) &hilo_id2);

  pthread_join(hilo_prod, NULL);
  pthread_join(hilo_cons, NULL);
  pthread_join(hilo_cons2, NULL);

  return 0;
}
