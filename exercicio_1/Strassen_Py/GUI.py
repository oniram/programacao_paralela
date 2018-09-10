from PyQt5 import QtWidgets, uic, QtGui
from Strassen import *
import sys
import numpy as np

class Janela_principal(QtWidgets.QMainWindow):

    def __init__(self):
        
        super(Janela_principal, self).__init__() #Ainda não entendi bem o que isso significa
        
        uic.loadUi('Strassen.ui', self) #Carrega o arquivo da interface gráfica
        
        self.show() #Mostra a janela principal
    
        self.calc.clicked.connect(self.calcular) #Define a ação que será executada quando o botão calcular for clicado
        self.actionSair.triggered.connect(self.close)
        self.actionSobre.triggered.connect(self.mostrar_Sobre)
        
    def calcular(self): #As funções podem estar fora, mas devem estar dentro da classe
        Check_ig = self.chk_ig.isChecked()
        Check_quad = self.chk_quad.isChecked()
        Check_pot = self.chk_pot.isChecked()
        Check_time = self.chk_time.isChecked()
        A = self.A_texto.toPlainText()
        A_temp = A.splitlines()
        A = np.fromstring(A_temp[0], sep =' ')
        for i in range(1, len(A_temp)):
            lin = np.fromstring(A_temp[i], sep =' ')
            A = np.vstack([A,lin])
        B = self.B_texto.toPlainText()
        B_temp = B.splitlines()
        B = np.fromstring(B_temp[0], sep =' ')
        for i in range(1, len(B_temp)):
            lin = np.fromstring(B_temp[i], sep =' ')
            B = np.vstack([B,lin])
        C,tempo = multi_strassen(A, B, Check_ig, Check_quad, Check_pot, Check_time)
        C_1 = np.array2string(C)
        self.C_mostra.setText(C_1)
        self.Tempo_mostra.setText(str(tempo))
        
    def mostrar_Sobre(self):
        self.aboutUi = Sobre_janela()
        self.aboutUi.SetupUi()
       

if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)
    window = Janela_principal()
    sys.exit(app.exec_())
    
    
class Sobre_janela(QtWidgets.QDialog):
    
    def SetupUi(self):
        uic.loadUi('Sobre.ui',self)
        self.exec_()    