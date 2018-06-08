import rank

file = open('grafo.csv', 'r')
linhas = file.readlines()
file.close()
matriz = []
for l in linhas:
    matriz.append([int(x) for x in l.split(';')])
entrada_rank = []
print matriz
