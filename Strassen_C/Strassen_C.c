#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <windows.h>

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


/* FUN합ES DE OPERA합ES MATRICIAIS */
int** somaMatriz(int **a, int **b, int **c, int tamanho, int ia, int ja, int ib, int jb, int ic, int jc){
    for(int i= 0; i< tamanho; i++){
        for(int j= 0; j< tamanho; j++){
            c[i+ic][j+jc] = a[i+ia][j+ja] + b[i+ib][j+jb];
        }
    }
    return c;
}

int** subMatriz(int **a, int **b, int **c, int tamanho, int ia, int ja, int ib, int jb, int ic, int jc){
    for(int i= 0; i< tamanho; i++){
        for(int j= 0; j< tamanho; j++){
            c[i+ic][j+jc] = a[i+ia][j+ja] - b[i+ib][j+jb];
        }
    }
    return c;
}

int** multMatriz(int **a, int **b, int **c, int tamanho, int ia, int ja, int ib, int jb, int ic, int jc){
    for(int i= 0; i< tamanho; i++){
        for(int j= 0; j< tamanho; j++){
            for(int k= 0; k< tamanho; k++){
                c[i+ic][j+jc]+= a[i+ia][k+ja]*b[k+ib][j+jb];
            }
        }
    }
    return c;
}
/* FIM FUN합ES DE OPERA합ES MATRICIAIS */


int main(){
/* DECLARA플O DE VARI햂EIS */
    int **A, **B, **C;
    int **M1, **M2, **M3, **M4, **M5, **M6, **M7, **la, **lb;
    int i, j, tam= 8, htam= tam/2; //tam = tamanho; htam = half-tamanho;

    struct timeval start, end, tempo; // variáveis para salvar o tempo

    //FILE *Tempo;
    //Tempo= fopen("Tempo.txt", "w");

    srand(time(NULL));
/* FIM DECLARA플O DE VARI햂EIS */

//for(int t= 0; t< 15; t++){

/* ALOCA플O DAS MATRIZES */
    A = (int **) calloc(tam, sizeof(int *));
    for(i= 0; i< tam; i++) A[i] = calloc(tam, sizeof(int));

    B = (int **) calloc(tam, sizeof(int *));
    for(i= 0; i< tam; i++) B[i] = calloc(tam, sizeof(int));

    C = (int **) calloc(tam, sizeof(int *));
    for(i= 0; i< tam; i++) C[i] = calloc(tam, sizeof(int));

    M1 = (int **) calloc(htam, sizeof(int *));
    for(i= 0; i< htam; i++) M1[i] = calloc(htam, sizeof(int));

    M2 = (int **) calloc(htam, sizeof(int *));
    for(i= 0; i< htam; i++) M2[i] = calloc(htam, sizeof(int));

    M3 = (int **) calloc(htam, sizeof(int *));
    for(i= 0; i< htam; i++) M3[i] = calloc(htam, sizeof(int));

    M4 = (int **) calloc(htam, sizeof(int *));
    for(i= 0; i< htam; i++) M4[i] = calloc(htam, sizeof(int));

    M5 = (int **) calloc(htam, sizeof(int *));
    for(i= 0; i< htam; i++) M5[i] = calloc(htam, sizeof(int));

    M6 = (int **) calloc(htam, sizeof(int *));
    for(i= 0; i< htam; i++) M6[i] = calloc(htam, sizeof(int));

    M7 = (int **) calloc(htam, sizeof(int *));
    for(i= 0; i< htam; i++) M7[i] = calloc(htam, sizeof(int));

    la = (int **) calloc(htam, sizeof(int *));
    for(i= 0; i< htam; i++) la[i] = calloc(htam, sizeof(int));

    lb = (int **) calloc(htam, sizeof(int *));
    for(i= 0; i< htam; i++) lb[i] = calloc(htam, sizeof(int));

    for(i = 0; i< tam; i++) for(j = 0; j< tam; j++){ // ALIMENTANDO AS MATRIZES A e B
        A[i][j] = rand()  % 10;
        B[i][j] = rand()  % 10;
    }
/* FIM ALOCA플O DAS MATRIZES */


/* IMPRIMIR MATRIZES A e B */
    printf("\nMatriz A:\n");
        for(i = 0; i< tam; i++){
            for(j = 0; j< tam; j++){
                printf("%d  ", A[i][j]);
            }
            printf("\n");
        }

    printf("\nMatriz B:\n");
        for(i = 0; i< tam; i++) {
            for(j = 0; j< tam; j++){
                printf("%d  ", B[i][j]);
            }
            printf("\n");
        }
/* FIM IMPRIMIR MATRIZES A e B */


    gettimeofday(&start, NULL);


/* CALCULO DOS TERMOS M */
    //M1
    multMatriz(somaMatriz(A, A, la, htam, 0, 0, htam, htam, 0, 0), somaMatriz(B, B, lb, htam, 0, 0, htam, htam, 0, 0), M1, htam, 0, 0, 0, 0, 0, 0);

    //M2
    multMatriz(somaMatriz(A, A, la, htam, htam, 0, htam, htam, 0, 0), B, M2, htam, 0, 0, 0, 0, 0, 0);

    //M3
    multMatriz(A, subMatriz(B, B, lb, htam, 0, htam, htam, htam, 0, 0), M3, htam, 0, 0, 0, 0, 0, 0);

    //M4
    multMatriz(A, subMatriz(B, B, lb, htam, htam, 0, 0, 0, 0, 0), M4, htam, htam, htam, 0, 0, 0, 0);

    //M5
    multMatriz(somaMatriz(A, A, la, htam, 0, 0, 0, htam, 0, 0), B, M5, htam, 0, 0, htam, htam, 0, 0);

    //M6
    multMatriz(subMatriz(A, A, la, htam, htam, 0, 0, 0, 0, 0), somaMatriz(B, B, lb, htam, 0, 0, 0, htam, 0, 0), M6, htam, 0, 0, 0, 0, 0, 0);

    //M7
    multMatriz(subMatriz(A, A, la, htam, 0, htam, htam, htam, 0, 0), somaMatriz(B, B, lb, htam, htam, 0, htam, htam, 0, 0), M7, htam, 0, 0, 0, 0, 0, 0);
/* FIM CALCULO DOS TERMOS M */


/* CALCULO C */
    //C_1_1
    subMatriz(somaMatriz(somaMatriz(M1, M4, C, htam, 0, 0, 0, 0, 0, 0), M7, C, htam, 0, 0, 0, 0, 0, 0), M5, C, htam, 0, 0, 0, 0, 0, 0);

    //C_1_2
    somaMatriz(M3, M5, C, htam, 0, 0, 0, 0, 0, htam);

    //C_2_1
    somaMatriz(M2, M4, C, htam, 0, 0, 0, 0, htam, 0);

    //C_2_2
    subMatriz(somaMatriz(somaMatriz(M3, M6, C, htam, 0, 0, 0, 0, htam, htam), M1, C, htam, htam, htam, 0, 0, htam, htam), M2, C, htam, htam, htam, 0, 0, htam, htam);

/* FIM CALCULO C */


    gettimeofday(&end, NULL);

    timersub(&end, &start, &tempo);


/* IMPRIMIR MATRIZ C */
    printf("\nMatriz C:\n");
        for(i = 0; i< tam; i++) {
            for(j = 0; j< tam; j++){
                printf("%d  ", C[i][j]);
            }
            printf("\n");
        }
/* FIM IMPRIMIR MATRI C */


    printf("Tempo de calculo: %lli.%lli\n", (long long int)tempo.tv_sec, (long long int)tempo.tv_usec);
    //fprintf(Tempo, "Tempo de calculo para matriz %d: %lli.%lli \n", tam, (long long int)tempo.tv_sec, (long long int)tempo.tv_usec);
    //tam = tam * 2; htam=tam/2;

    free(A);
    free(B);
    free(C);
    free(M1);
    free(M2);
    free(M3);
    free(M4);
    free(M5);
    free(M6);
    free(M7);
    free(la);
    free(lb);
    //Sleep(0.01);
//}

//fclose(Tempo);

return 0;
}//FIM MAIN
