from methods import *
import matplotlib.pyplot as plt
from math import *

#Para linearizarmos a função, precisamos chegar em ln(y) - ln(x) = ln(a) + b * x

x = [0.3553, 0.4225, 0.7419, 0.9359, 1.0747, 1.4651, 1.5778, 1.9783, 2.0256, 2.2976, 2.6911, 2.9032, 3.0333, 3.3118, 3.5576, 3.6806, 4.0505, 4.2818, 4.5608, 4.6835, 5.0243, 5.2915, 5.4499, 5.7181, 5.9659, 6.2108, 6.3111, 6.5065, 6.7553, 7.1603, 7.2414, 7.6182, 7.8766, 7.8864, 8.2523, 8.4537, 8.808, 8.9434, 9.2444, 9.4825, 9.654, 9.9638]
y = [1.3691, 1.5829, 2.5114, 2.9544, 3.4041, 3.928, 4.0982, 4.6248, 4.5845, 4.7643, 4.9321, 4.9737, 5.0198, 5.0486, 5.0695, 4.9802, 4.9392, 4.8252, 4.7376, 4.665, 4.4966, 4.3828, 4.2935, 4.1717, 4.0346, 3.9314, 3.8083, 3.7326, 3.623, 3.344, 3.3165, 3.0955, 3.0043, 2.9431, 2.7792, 2.7314, 2.5122, 2.4461, 2.3135, 2.2105, 2.1812, 1.9988]
values = [3.6687, 6.3935, 8.4713, 9.7183, 9.8564]

logxy = list()

#linearização, obtendo ln(y) - ln(x), isso é o que vai entrar no lugar de y no best_poly
for i in range(0, len(x)):
    logxy.append(log(y[i]) - log(x[i]))

z, b = best_poly(x,logxy, 1) 

a = exp(z) # a função te retorna um valor z = ln(a), então isola a e obtém a = exp(z)

print('Coefs:\n',f'{a}, {b}', end=',')

def p(x, a, b):
	return a * x * exp(b*x)

print()
print('Values:\n')
for value in values:
    print(f'{(p(value, a, b))}', end=", ")
print("")
