from methods import *
import matplotlib.pyplot as plt
from math import *

x = [1.9051, 2.126, 3.1312, 4.4707, 4.8496, 6.4564, 7.1633, 7.8266, 8.4376, 9.9755, 10.8419, 11.8465]
y = [2.329, 2.5908, 3.426, 3.9141, 4.1668, 4.419, 4.3904, 4.4699, 4.5587, 4.5684, 4.5684, 4.6546]
values = [5.0998, 6.1473, 10.9026]

#linearização, transformando y em 1/y e x em 1/x
for i in range(0, len(y)):
    y[i] = 1/y[i]

for i in range(0, len(x)):
    x[i] = 1/x[i]

z, w = best_poly(x,y, 1) 

a = 1/z # a função te retorna um valor z = ln(a), então isola a e obtém a = exp(z)
b = a * w
print('Coefs:\n',f'{a}, {b}', end=',')

def p(x, a, b):
	return a * (x/(x+b))

print()
print('Values:\n')
for value in values:
    print(f'{(p(value, a, b))}', end=", ")
print("")
