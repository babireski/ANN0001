from methods import *
import matplotlib.pyplot as plt
from math import *

#funções do tipo y = ((a+sqrt(x))/b*sqrt(x))²

x = [0.609, 1.3211, 2.3037, 3.2166, 4.3046, 4.7449, 5.6867, 6.0573, 6.8703, 8.2062, 9.0634, 9.9198]
y = [8.3115, 4.5178, 3.0558, 2.4866, 1.9705, 1.8978, 1.6822, 1.7027, 1.7381, 1.4495, 1.4943, 1.2548]
values = [1.5748, 1.7752, 5.2732]

#linearização, transformando x em sqrt(x)

for i in range(0, len(x)):
    x[i] = 1/sqrt(x[i])

for i in range(0, len(y)):
    y[i] = sqrt(y[i])

    

w, z = best_poly(x,y, 1) 

b = 1/w
a = z*b


print('Coefs:\n',f'{a}, {b}', end=',')

def p(x, a, b):
	return pow((a+sqrt(x))/(b*sqrt(x)),2)

print()
print('Values:\n')
for value in values:
    print(f'{(p(value, a, b))}', end=", ")
print("")