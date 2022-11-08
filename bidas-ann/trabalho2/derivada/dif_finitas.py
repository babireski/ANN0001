from methods import *

def f(x):
    return  x**2 * math.exp(-x) * math.cos(x) + 1

k = 5 # ordem da derivada
n = 15 # número de pontos
x0 = -1.5758
x = [-1.8131, -1.7612, -1.7529, -1.6987, -1.6697, -1.6451, -1.613, -1.5889, -1.5429, -1.507, -1.4631, -1.4507, -1.3992, -1.3618, -1.3502]

y = [f(xi) for xi in x]

coeffs = coeffs_dif_fin(x0, x, k)
aprox = dif_fin(coeffs, y)

print(f'{coeffs}')
print(f'{aprox}')