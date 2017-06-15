#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N_THREAD 2
sem_t teste;

void *funcao(void *arg)
{
	printf("t1 %d\n", teste);// entendendo wait

	sem_trywait(&teste);

	printf("t2 %d\n", teste);// entendendo wait

	int *pvalor;
	pvalor = arg;
	printf("Thread %d executando... \n", *pvalor);
	printf("Thread %d finalizada! \n", *pvalor);

	sem_post(&teste);
}

int main()
{
	sem_init(&teste, 0, 0);
	pthread_t threads[N_THREAD];
	int i, arg[N_THREAD];

	for(i = 0; i < N_THREAD; i++){
		arg[i] = i + 1;
		pthread_create(&threads[i], NULL, funcao, (void *)&arg[i]);
	}

//	for(i = 0; i < N_THREAD; i++)
//		pthread_join(threads[i], NULL);

	printf("\n");

	return 0;
}
