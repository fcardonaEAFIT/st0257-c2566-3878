#include<iostream>
#include<semaphore.h>
#include<pthread.h>
#include<cstdlib>
#include<unistd.h>

enum SEMAFOROS { NO_TABACO, NO_PAPEL, NO_CERRILLA, AGENTE };

sem_t semaforos[AGENTE + 1];

void* fumador(void *);

int
main(int argc, char* argv[]) {
  
  for (int i = 0; i < AGENTE + 1; i++) {
    sem_init(&semaforos[i], 0, 0);
  }

  pthread_t fumadores[AGENTE];
  
  srand(time(NULL));

  for (int i = 0; i < AGENTE; i++) {
    pthread_create(&fumadores[i], NULL, fumador, (void *) i);
  }
  
  while(1) {
    int elemento = random() % 3;
    sem_post(&semaforos[elemento]);
    sem_post(&semaforos[AGENTE]);
  }

  return 0;
}

void* fumador(void *arg) {
  SEMAFOROS id = (SEMAFOROS) arg;
  for(;;) {
    sem_wait(&semaforos[id]);
    std::cout << "Soy el fumador: " << id << " Estoy fumando" << endl;
    sleep(random() % 5 + 1);
    sem_post(&semaforos[AGENTE]);
  }
}
		       
