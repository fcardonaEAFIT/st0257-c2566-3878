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
		       
pthread_mutex_t mesa = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
pthread_cond_t  conds[4] = {
  PTHREAD_COND_INITIALIZER,
  PTHREAD_COND_INITIALIZER,
  PTHREAD_COND_INITIALIZER,
  PTHREAD_COND_INITIALIZER };

void* fumador(void *fumador_id);

int
main(int argc, char* argv[]) {
  
  pthread_t fumadores[AGENTE];
  
  srand(time(NULL));

  for (int i = 0; i < AGENTE; i++) {
    INGREDIENTE_NO_NECESARIO *id = new INGREDIENTE_NO_NECESARIO();
    *id = (INGREDIENTE_NO_NECESARIO) i;
    pthread_create(&fumadores[i], NULL, fumador, (void *) id);
  }
  
  while(1) { // AGENTE
    int elemento = random() % 3;

    std::cout << "Agente poniendo en la mesa: "
	      << ingredientes_necesarios[elemento]
	      << std::endl;
    // pthread_mutex_lock(&mesa);
    pthread_cond_signal(&conds[elemento]);
    // pthread_mutex_unlock(&mesa);
    
    sleep(random() % 3 + 1);
    pthread_mutex_lock(&mesa);
    pthread_cond_wait(&conds[AGENTE], &mesa);
    pthread_mutex_unlock(&mesa);
  }

  return 0;
}

void* fumador(void *fumador_id) {
  INGREDIENTE_NO_NECESARIO *id = (INGREDIENTE_NO_NECESARIO*) fumador_id;
  for(;;) {

    // Esperando por los ingredientes restantes
    pthread_mutex_lock(&mesa);
    pthread_cond_wait(&conds[*id], &mesa);
    pthread_mutex_unlock(&mesa);
    
    std::cout << "Fumador con "
	      << ingrediente[*id]
	      << " recibio "
	      << ingredientes_necesarios[*id]
	      << " los enrollo y está fumando." << std::endl;
    sleep(random() % 6 + 1);
    
    // pthread_mutex_lock(&mesa);
    pthread_cond_signal(&conds[AGENTE]);
    // pthread_mutex_unlock(&mesa);
  }
}
		       
