import pandas as pd
import os


for i in range(41000, 46001, 1000):
    os.system('gcc main.c -o main')
    os.system(f'./main {i}')

dados = pd.read_csv('dados_iter_trocada.csv')
print(dados)