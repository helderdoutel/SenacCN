def seno(x):
    a = 0
    for y in range(20):
        a += ((-1)**y)*((x**((2*y)+1))/f((2*y)+1))
    return a

def f(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    if n > 1:
        return f(n - 1) * n

print('aqui ' + str(seno( (45*(3.14159265/180)) )))
