#include<iostream>
#include<semaphore.h>
#include<pthread.h>
#include<cstdlib>
#include<unistd.h>

enum INGREDIENTE_NO_NECESARIO { NO_TABACO, NO_PAPEL, NO_CERRILLA, AGENTE };

const char *ingredientes_necesarios[] = {
  "papel y cerilla",
  "tabaco y cerilla",
  "tabaco y papel"
};

const char* ingrediente[] = {
  "tabaco",
  "papel",
  "cerilla"
};
		       
sem_t semaforos[AGENTE + 1];

void* fumador(void *fumador_id);

int
main(int argc, char* argv[]) {
  
  for (int i = 0; i < AGENTE + 1; i++) {
    sem_init(&semaforos[i], 0, 0);
  }

  pthread_t fumadores[AGENTE];
  
  srand(time(NULL));

  for (int i = 0; i < AGENTE; i++) {
    INGREDIENTE_NO_NECESARIO *id = new INGREDIENTE_NO_NECESARIO();
    *id = (INGREDIENTE_NO_NECESARIO) i;
    pthread_create(&fumadores[i], NULL, fumador, (void *) id);
  }
  
  while(1) {
    int elemento = random() % 3;

    std::cout << "Agente poniendo en la mesa: "
	      << ingredientes_necesarios[elemento]
	      << std::endl;
    sleep(random() % 3 + 1);
    sem_post(&semaforos[elemento]); 
    sem_wait(&semaforos[AGENTE]);
  }

  return 0;
}

void* fumador(void *fumador_id) {
  INGREDIENTE_NO_NECESARIO *id = (INGREDIENTE_NO_NECESARIO*) fumador_id;
  for(;;) {
    
    sem_wait(&semaforos[*id]);
    std::cout << "Fumador con "
	      << ingrediente[*id]
	      << " recibio "
	      << ingredientes_necesarios[*id]
	      << " los enrollo y está fumando." << std::endl;
    sleep(random() % 6 + 1);
    sem_post(&semaforos[AGENTE]);
  }
}
		       
