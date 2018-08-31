#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int main()
{
	int SIZE = 400;
    int matriz_1[SIZE][SIZE];
    int matriz_2[SIZE][SIZE];
    int matriz_resultado[SIZE][SIZE];
    int i, j, k;
    int soma = 0;
    struct timeval start, end, tempo;

    srand(time(NULL)); //evitar sequencias repetidas no random


    for(i = 0; i<SIZE; i++) {
    	for(j = 0; j<SIZE; j++){
            matriz_1[i][j] = rand()  % 10;
            matriz_2[i][j] = rand()  % 10;
    	}
    }


    gettimeofday(&start, NULL);
    for (i = 0; i < SIZE; i++) {
      for (j = 0; j < SIZE; j++) {
        for (k = 0; k < SIZE; k++) {
          soma = soma + matriz_1[i][k]*matriz_2[k][j];
        }
 
        matriz_resultado[i][j] = soma;
        soma = 0;
      }
    }

    gettimeofday(&end, NULL);
    
    timersub(&end, &start, &tempo);
	printf("Tempo execucao: %ld.%06ld\n", (long int)tempo.tv_sec, (long int)tempo.tv_usec);

    return 0;
}

