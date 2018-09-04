import numpy as np
import math
import datetime

def multi_strassen(A,B,check_dim = True, check_ig = True, check_quad = True, check_pot = True):
    
    def Strassen(matriz_1,matriz_2): # Função do algoritmo de Strassen para multiplicação de matrizes do tipo 2x2
        if (matriz_1.shape[0] != 2) or (matriz_1.shape[1] != 2) or (matriz_2.shape[0] != 2) or (matriz_2.shape[1] != 2):
            print("As matrizes devem ser do tipo 2x2")
            return None

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
    
    inicio = datetime.datetime.now()
    C = np.zeros([A.shape[0],B.shape[1]]) #Guarda o tamanho original da matriz multiplicada

    #Parte 1: Checagem das condições pré-estabelecidas
    if (A.shape[1] != B.shape[0]):
        print("Erro: Não é possível realizar a multiplicação C = A * B com as matrizes fornecidas")

    if check_dim:
        
        if (len(A.shape) != 2) or (len(B.shape) != 2): #Checa a dimensão da matriz
            print("Erro: As matrizes devem ser bidimensionais")
            return None

    if check_ig:
        
        if (A.shape != B.shape): #Checa se as matrizes possuem mesma dimensão
            print("Erro: As matrizes devem possuir mesmas dimensões")
            return None
       
    if check_quad:
        
        if ((A.shape[0] - A.shape[1]) != 0) or ((B.shape[0] - B.shape[1]) != 0):
            print("Erro: As matrizes devem ser ambas quadradas")
            return None

    if check_pot:
        
        if (math.ceil(math.log2(A.shape[0]) != math.floor(math.log2(A.shape[0])))) or (math.ceil(math.log2(A.shape[1]) != math.floor(math.log2(A.shape[1])))):
            print("A matriz A será modificada, acrescentando-se zeros para que torne-se uma matriz do tipo 2^n x 2^n")
            linhas = 2**math.ceil(math.log2(A.shape[0])) - A.shape[0] #Calcula quantas linhas faltam para um quadrado de dois
            colunas = 2**math.ceil(math.log2(A.shape[1])) - A.shape[1] #Calcula quantas colunas faltam para um quadrado de dois
            if linhas > colunas:
                matriz_auxiliar = np.zeros([linhas,A.shape[1]])
                A = np.vstack((A,matriz_auxiliar))
                matriz_auxiliar = np.zeros([A.shape[0],A.shape[0]-A.shape[1]])
                A = np.hstack((A,matriz_auxiliar))

            elif colunas >= linhas:
                matriz_auxiliar = np.zeros([A.shape[0],colunas])
                A = np.hstack((A,matriz_auxiliar))
                matriz_auxiliar = np.zeros([A.shape[1]-A.shape[0],A.shape[1]])
                A = np.vstack((A,matriz_auxiliar))

        if (math.ceil(math.log2(B.shape[0]) != math.floor(math.log2(B.shape[0])))) or (math.ceil(math.log2(B.shape[1]) != math.floor(math.log2(B.shape[1])))):
            print("A matriz B será modificada, acrescentando-se zeros para que torne-se uma matriz do tipo 2^n x 2^n")
            linhas = 2**math.ceil(math.log2(B.shape[0])) - B.shape[0] #Calcula quantas linhas faltam para um quadrado de dois
            colunas = 2**math.ceil(math.log2(B.shape[1])) - B.shape[1] #Calcula quantas colunas faltam para um quadrado de dois
            if linhas > colunas:
                matriz_auxiliar = np.zeros([linhas,B.shape[1]])
                B = np.vstack((B,matriz_auxiliar))
                matriz_auxiliar = np.zeros([B.shape[0],B.shape[0]-B.shape[1]])
                B = np.hstack((B,matriz_auxiliar))

            elif colunas >= linhas:
                matriz_auxiliar = np.zeros([B.shape[0],colunas])
                B = np.hstack((B,matriz_auxiliar))
                matriz_auxiliar = np.zeros([B.shape[1]-B.shape[0],B.shape[1]])
                B = np.vstack((B,matriz_auxiliar))


    #Multiplicação de fato das matrizes
    
    D = np.zeros_like(A)
    for i in range(0,A.shape[0],2):
        for j in range(0,B.shape[1],2):
            soma = 0
            for k in range(0,A.shape[1],2):
                soma = soma + Strassen(A[i:i+2,k:k+2],B[k:k+2,j:j+2])
            D[i:i+2,j:j+2] = soma
    C = D[0:C.shape[0],0:C.shape[1]]
    print (C)
    fim = datetime.datetime.now()
    print("Tempo de execução = ", fim - inicio)
    return C