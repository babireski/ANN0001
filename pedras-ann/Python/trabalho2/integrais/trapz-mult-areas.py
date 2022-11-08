import math

def trapz(f, a, b, n):
    h = (b - a) / n
    soma = 0
    for k in range(1, n):
        soma += f(a + k * h)
    soma *= 2
    soma += f(a)
    soma += f(b)
    soma *= (h/2.0)
    print(f'Area aproximadamente: {soma}')

def f(x):
    return math.sqrt(math.sin(math.cos(math.log(x**2 + 1) + 2) + 3) + 4)

def trapzPonto(x, y):
    tam = len(x) - 1
    somas = 0
    for i in range(tam):
        h = x[i+1] - x[i]
        somas += (h/2) * (y[i] + y[i+1])
    print(f'Area = {somas}')

x = [0,
5 / 3600,	
10 / 3600,
15 / 3600,
20 / 3600,
25 / 3600,
30 / 3600,
35 / 3600,
40 / 3600,
45 / 3600,
50 / 3600,
55 / 3600,
60 / 3600,
65 / 3600,
70 / 3600,
75 / 3600,
80 / 3600,
85 / 3600,
90 / 3600]

y = [0,
100,
225,
357,
509,
675,
826,
971,
1091,
1203,
1322,
1463,
1634,
1824,
2045,
2315,
2596,
2902,
3206]

trapzPonto(x, y)