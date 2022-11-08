from methods import *
import matplotlib.pyplot as plt
from math import *

#funcoes do tipo y = e^x
x = [0.0543, 0.1778, 0.4085, 0.5729, 0.8089, 0.9865, 1.1215, 1.175, 1.4657, 1.5291, 1.7638, 1.964]
y = [3.7112, 8.8691, 7.0247, 14.6952, 19.6816, 26.8709, 33.9893, 34.763, 62.3342, 72.1847, 106.1241, 151.7351]
values = [0.3357, 0.3585, 1.295]

#linearização, transformando y em ln(y)
for i in range(0, len(y)):
    y[i] = log(y[i])
    
z, b = best_poly(x,y, 1) 

a = exp(z) # a função te retorna um valor z = ln(a), então isola a e obtém a = exp(z)
print('Coefs:\n',f'{a}, {b}', end=',')

def p(x, a, b):
	return a * exp(b*x) 

print()
print('Values:\n')
for value in values:
    print(f'{(p(value, a, b))}', end=", ")
print("")
