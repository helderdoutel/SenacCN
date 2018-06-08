import rank as r

file = open('grafo.csv', 'r')
linhas = file.readlines()
file.close()
matriz = []
matriz_referencia = []

for l in linhas:
    matriz.append([int(x) for x in l.split(';')])

nos = []
for x in range(len(matriz)):
    for i in range(len(matriz[x])):
        if matriz[x][i] not in nos:
            nos.append(matriz[x][i])
entrada_rank = []
dimensao = len(nos)

for x in range(dimensao):
    matriz_referencia.append([])
    for y in range(dimensao):
        matriz_referencia[x].append(0)

for x in range(len(matriz)):
    matriz_referencia[matriz[x][0] - 1][matriz[x][1] - 1] += 1

matriz_pesos = []
for x in range(dimensao):
    matriz_pesos.append([])
    for y in range(dimensao):
        matriz_pesos[x].append(0)

recebe = {}
for x in range(dimensao):
    for y in range(dimensao):
        if (x + 1) not in recebe.keys():
            recebe[x + 1] = matriz_referencia[x][y]
        else:
            recebe[x + 1] += matriz_referencia[x][y]

for x in range(dimensao):
    for y in range(dimensao):
        if matriz_referencia[y][x] == 1:
            matriz_pesos[x][y] = float(1) / recebe[y + 1] * 1.0

r.rank(entrada=matriz_pesos, dimensao=dimensao)
print matriz_pesos
