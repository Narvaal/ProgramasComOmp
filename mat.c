/*
1)  Crie um programa em C que multiplica todos os elementos de um array por 4 ou por um valor fornecido pelo usuário
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

void function();
int arr[4] =  {1,2,3,4};

int main(int argc, char* argv[])
{
    int thread_count = strtol(argv[1],NULL,10);
    #pragma omp parallel num_threads(thread_count) 
    function();
	return 0;
}

void function()
{
  int idThread = omp_get_thread_num();
  int result = arr[idThread] *= 4;
  printf("Thread - %d, resultado %d \n",idThread,result);
}
