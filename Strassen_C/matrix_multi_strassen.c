#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

//Definição da rotina timersub
#ifndef timersub
#define timersub(a, b, result) \
        do { \
                (result)->tv_sec = (a)->tv_sec - (b)->tv_sec; \
                (result)->tv_usec = (a)->tv_usec - (b)->tv_usec; \
                if ((result)->tv_usec < 0) { \
                        --(result)->tv_sec; \
                        (result)->tv_usec += 1000000; \
                } \
        } while (0)
#endif

int main(){
    int SIZE = 4;

    int a[SIZE][SIZE];
    int b[SIZE][SIZE];
    int c[SIZE][SIZE];
    int t[SIZE][SIZE];

    int m1, m2, m3, m4, m5, m6, m7;

    int i = 0, j = 0, m, n;

    struct timeval start, end, tempo;

    srand(time(NULL)); //evitar sequencias repetidas no random

    for(m = 0; m<SIZE; m++) {
        for(n = 0; n<SIZE; n++){
            a[m][n] = rand()  % 10;
            b[m][n] = rand()  % 10;
    	}
    }

    printf("\nMatriz A:\n");
    for(m = 0; m<SIZE; m++) {
        for(n = 0; n<SIZE; n++){
            printf("%d  ", a[m][n]);
        }
    	printf("\n");
    }

    printf("\nMatriz B:\n");
    for(m = 0; m<SIZE; m++) {
        for(n = 0; n<SIZE; n++){
            printf("%d  ", b[m][n]);
        }
    	printf("\n");
    }

    gettimeofday(&start, NULL);

    while(i < SIZE){
        if(j < SIZE){
            printf("%d %d \t",i , j);
            m1 = (a[i][j] + a[i+1][j+1])*(b[i][j] + b[i+1][j+1]);
            m2 = (a[i+1][j] + a[i+1][j+1]) * b[i][j];
            m3 = a[i][j] * (b[i][j+1] - b[i+1][j+1]);
            m4 = a[i+1][j+1] * (b[i+1][j] - b[i][j]);
            m5 = (a[i][j] + a[i][j+1]) * b[i+1][j+1];
            m6 = (a[i+1][j] - a[i][j]) * (b[i][j] + b[i][j+1]);
            m7 = (a[i][j+1] - a[i+1][j+1]) * (b[i+1][j] + b[i+1][j+1]);

            c[i][j] = m1 + m4 - m5 + m7;
            c[i][j+1] = m3 + m5;
            c[i+1][j] = m2 + m4;
            c[i+1][j+1] = m1 - m2 + m3 + m6;
            j = j + 2;
        }
        else{
            i = i + 2;
            j = 0;
        }
    }

    gettimeofday(&end, NULL);

    timersub(&end, &start, &tempo);

    printf("\nMatriz C:\n");
    for(m = 0; m<SIZE; m++) {
        for(n = 0; n<SIZE; n++){
            printf("%d  ", c[m][n]);
        }
    	printf("\n");
    }

	printf("\nTempo de calculo: %ld.%06ld\n", (long int)tempo.tv_sec, (long int)tempo.tv_usec);


    return 0;
}
