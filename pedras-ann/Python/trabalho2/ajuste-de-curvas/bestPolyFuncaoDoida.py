from methods import *
import matplotlib.pyplot as plt
from math import *

#funções do tipo x = e^((y-b)/a)

x = [1.1119, 2.0585, 2.802, 3.4131, 4.2272, 4.9, 5.6772, 6.596, 7.7118, 8.3763, 8.7087, 9.282]
y = [3.4025, 5.0581, 5.8566, 6.4725, 7.0345, 7.3919, 7.8129, 8.2241, 8.6033, 8.927, 8.9997, 9.103]
values = [2.1038, 2.4903, 6.4518]

#linearização, transformando x em ln(x)

for i in range(0, len(x)):
    x[i] = log(x[i])

b, a = best_poly(x,y, 1) 

print('Coefs:\n',f'{a}, {b}', end=',')

def p(x, a, b):
	return a * log(x) + b

print()
print('Values:\n')
for value in values:
    print(f'{(p(value, a, b))}', end=", ")
print("")