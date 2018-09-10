import numpy as np
import datetime

def multiplica (A,B):
    
    inicio = datetime.datetime.now()
    
    C = np.zeros_like(A)
    for i in range(0,A.shape[0]):
        for j in range(0,B.shape[1]):
            soma = 0
            for k in range(0,A.shape[1]):
                soma = soma + A[i,k]*B[k,j]
            C[i,j] = soma

    fim = datetime.datetime.now()
    tempo = fim - inicio
    
    return C, tempo

def Strassen(matriz_1,matriz_2): # Função do algoritmo de Strassen para multiplicação de matrizes do tipo 2x2

    M1 = (matriz_1[0,0] + matriz_1[1,1]) * (matriz_2[0,0] + matriz_2[1,1])
    M2 = (matriz_1[1,0] + matriz_1[1,1]) * matriz_2[0,0]
    M3 = matriz_1[0,0] * (matriz_2[0,1] - matriz_2[1,1])
    M4 = matriz_1[1,1] * (matriz_2[1,0] - matriz_2[0,0])
    M5 = (matriz_1[0,0] + matriz_1 [0,1]) * matriz_2[1,1]
    M6 = (matriz_1[1,0] - matriz_1[0,0]) * (matriz_2[0,0] + matriz_2[0,1])
    M7 = (matriz_1[0,1] - matriz_1[1,1]) * (matriz_2[1,0] + matriz_2[1,1])

    Resultado = np.zeros([2,2])
    Resultado[0,0] = M1 + M4 - M5 + M7
    Resultado[0,1] = M3 + M5
    Resultado[1,0] = M2 + M4
    Resultado[1,1] = M1 - M2 + M3 + M6

    return Resultado
    
def Strassen_simples(A,B):
    
    inicio = datetime.datetime.now()

    C = np.zeros_like(A)
    for i in range(0,A.shape[0],2):
        for j in range(0,B.shape[1],2):
            soma = 0
            for k in range(0,A.shape[1],2):
                soma = soma + Strassen(A[i:i+2,k:k+2],B[k:k+2,j:j+2])
            C[i:i+2,j:j+2] = soma

    fim = datetime.datetime.now()
    tempo = fim - inicio
    
    return C, tempo

n = 2
print("| Algoritmo | Ordem \t | Tempo")
print("|-----------|------------|---------------")
while n < 3:
    A = np.ones([n,n])
    B = np.ones([n,n])
    C,tempo = Strassen_simples(A,B)
    C1, tempo1 = multiplica (A,B)
    print("| Strassen  | n = ",n,"\t | ",tempo)
    print("| Normal    | n = ",n,"\t | ",tempo1)
    n = n*2
