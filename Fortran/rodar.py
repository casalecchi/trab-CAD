import pandas as pd
import os

os.system('gfortran main.f90 main.f90 -o main')
for i in range(37000, 46001, 500):
    os.system(f'./main {i}')

dados = pd.read_csv('dados_f_trocado.csv')
print(dados)