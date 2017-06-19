#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

void myfunc1 ( void *ptr );
void myfunc2 ( void *ptr );

char buf[20];// Variavel global de 20 Byts
sem_t mutex;

int main(int argc, char *argv[])
{
  pthread_t thread1;
  pthread_t thread2;

  char *msg1 = "Thread 1";
  char *msg2 = "Thread 2";

  /* Parametros sem_init
   o primeiro é o semaforo
   o segundo 1 ou 0 representa true or false, se pode ou nao usar em outro processo
   o terceiro é o valor inicial do semaforo */
  sem_init(&mutex, 0, 1);

  // Cada thread usa uma funcao
  pthread_create (&thread1, NULL, (void *) &myfunc1, (void *) msg1);
  pthread_create (&thread2, NULL, (void *) &myfunc2, (void *) msg2);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  sem_destroy(&mutex);

  return 0;
}

// Nas funcoes usamos sem_wait e sem_post para proteger o dado, para que não leia antes de escrever
void myfunc1 ( void *ptr)// Essa thread escreve
{
  char *msg = (char *)ptr;

  printf("%s\n", msg);
  
  sem_wait(&mutex);// Trava a thread
  sprintf(buf, "%s", "Escrito na thread 1");
  printf("%s\n", buf);
  sem_post(&mutex);// Libera a thread

  pthread_exit(0);
}

void myfunc2 (void *ptr)// Essa thread le
{
  char *msg = (char *)ptr;

  printf("%s\n", msg);

  sem_wait(&mutex);
  sprintf(buf, "%s", "Escrito na thread 2");
  printf("%s\n", buf);
  sem_post(&mutex);

  pthread_exit(0);
}
