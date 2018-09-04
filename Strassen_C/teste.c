#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* FUNÇÕES DE OPERAÇÕES MATRICIAIS */
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
                c[i+ic][j+jc] += a[i+ia][k+ja]*b[k+ib][j+jb];
            }
        }
    }
    return c;
}
/* FIM FUNÇÕES DE OPERAÇÕES MATRICIAIS */


int main(){
/* DECLARAÇÃO DE VARIÁVEIS */
    int **A, **B, **C;
    int **M1, **M2, **M3, **M4, **M5, **M6, **M7, **la, **lb;
    int i, j, tam= 8, htam= tam/2; //tam = tamanho; htam = half-tamanho;

    srand(time(NULL));
/* FIM DECLARAÇÃO DE VARIÁVEIS */


/* ALOCAÇÃO DAS MATRIZES */
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
/* FIM ALOCAÇÃO DAS MATRIZES */


/* IMPRIMIR MATRIZES A e B */
    printf("\nMatriz A:\n");
        for(i = 0; i< tam; i++) {
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
    subMatriz(somaMatriz(somaMatriz(M3, M6, C, htam, 0, 0, 0, 0, htam, htam), M1, C, htam, 0, 0, 0, 0, htam, htam), M2, C, htam, 0, 0, 0, 0, htam, htam);
/* FIM CALCULO C */


/* IMPRIMIR MATRIZ C */
    printf("\nMatriz C:\n");
        for(i = 0; i< tam; i++) {
            for(j = 0; j< tam; j++){
                printf("%d  ", C[i][j]);
            }
            printf("\n");
        }
/* FIM IMPRIMIR MATRI C */

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

return 0;
}//FIM MAIN
