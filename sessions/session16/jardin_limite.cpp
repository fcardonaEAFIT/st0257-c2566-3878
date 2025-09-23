#include<iostream>
#include<semaphore.h>
#include<pthread.h>
#include<cstdlib>
#include<unistd.h>

int contador = 0;
sem_t mutex;
sem_t limite;

void entrar_jardin() {
  sem_wait(&mutex); // Entra a la sección critica
  contador++;
  sem_post(&mutex);
}

void salir_jardin() {
  sem_wait(&mutex);
  contador--;
  sem_post(&mutex);
}

void* visitante(void *arg) {
  for(;;) {
    // Por fuera del jardin
    sleep(random() % 5 + 1);
    sem_wait(&limite);
    entrar_jardin();
    // Dentro del jardin
    sleep(random() % 6 + 1);
    salir_jardin();
    sem_post(&limite);
  }
}

void* administrador(void* arg) {
  for (;;) {
    sleep(random() % 15 + 1);
    sem_wait(&mutex);
    std::cout << "Contador: " << contador << std::endl;
    sem_post(&mutex);
  }   
}

#define MAX_VISITANTES 200
#define LIMITE         MAX_VISITANTES / 2

int
main(int argc, char *argv[]) {
			  
  sem_init(&mutex, 0, 1);
  sem_init(&limite, 0, LIMITE);
  
  srandom(time(NULL));

  pthread_t hilos[MAX_VISITANTES + 1];
  pthread_create(&hilos[0], NULL, administrador, NULL);
		       
  for (int i = 0; i < MAX_VISITANTES; i++) {
    pthread_create(&hilos[i + 1], NULL, visitante, NULL);
  }

  void *retval;
  pthread_join(hilos[0], &retval);
  
  return 0;
}
