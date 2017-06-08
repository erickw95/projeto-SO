#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 6
//#define SEM 1
int SEM = 1;
int ct = 0;

void *funcao(void *arg)
{
   printf("func 1\n");
   return (NULL);
}

int down(SEM S)// Wait
{
  if(S == 0)
  {
    //bloqueia processo;
    S--;
  }
  return SEM;
}

int up(SEM S)// Signal
{
  if(S != 0)
    S++;
  //else
    //desbloqueia processo;
  return SEM;
