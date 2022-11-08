from re import X
from methods import *
import matplotlib.pyplot as plt
from math import *

x = [1.5231, 2.8298, 3.5702, 4.5511, 5.4029, 5.975, 6.7117, 7.6719, 9.0679, 9.7496, 10.6332, 11.5319]
y = [1.3082, 2.3502, 2.644, 2.8834, 2.9709, 3.1822, 3.1721, 3.2365, 3.2584, 3.3281, 3.2997, 3.2708]
values = [2.6809, 8.9586, 9.8067]

#linearização, transformando y em 1/y e x em 1/x**2
for i in range(0, len(y)):
    y[i] = 1/y[i]

for i in range(0, len(x)):
    x[i] = pow(1/x[i],2)

    

z, w = best_poly(x,y, 1) 

a = 1/z # a função te retorna um valor z = ln(a), então isola a e obtém a = exp(z)
b = a * w
print('Coefs:\n',f'{a}, {b}', end=',')

def p(x, a, b):
	return a * (x**2/(x**2+b))

print()
print('Values:\n')
for value in values:
    print(f'{(p(value, a, b))}', end=", ")
print("")
