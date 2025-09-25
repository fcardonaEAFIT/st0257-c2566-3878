#include<iostream>
#include<semaphore.h>
#include<pthread.h>
#include<cstdlib>
#include<unistd.h>
#define LIMITE 100

int contador = 0;
pthread_mutex_t mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
pthread_cond_t jardin_lleno = PTHREAD_COND_INITIALIZER;

void entrar_jardin() {
  pthread_mutex_lock(&mutex); // Entra a la sección critica
  while (contador + 1 == LIMITE) {
    pthread_cond_wait(&jardin_lleno, &mutex);
  }
  contador++;
  pthread_mutex_unlock(&mutex);
}

void salir_jardin() {
  pthread_mutex_lock(&mutex);
  contador--;
  
  if (contador + 1 == LIMITE) {
    pthread_cond_signal(&jardin_lleno);
  }
    
  pthread_mutex_unlock(&mutex);
}

void* visitante(void *arg) {
  for(;;) {
    // Por fuera del jardin
    sleep(random() % 5 + 1);
    entrar_jardin();
    // Dentro del jardin
    sleep(random() % 6 + 1);
    salir_jardin();
  }
}

void* administrador(void* arg) {
  for (;;) {
    sleep(random() % 15 + 1);
    pthread_mutex_lock(&mutex);
    std::cout << "Contador: " << contador << std::endl;
    pthread_mutex_unlock(&mutex);
  }   
}

#define MAX_VISITANTES 200

int
main(int argc, char *argv[]) {
			  
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
