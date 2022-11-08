from methods import *
import matplotlib.pyplot as plt
from math import *


x = [0.0501, 0.0673, 0.1119, 0.2169, 0.2414, 0.2962, 0.3886, 0.4173, 0.4763, 0.5386, 0.5682, 0.6545, 0.6884, 0.7586, 0.8107, 0.8813, 0.936, 0.9486, 1.0363, 1.082, 1.1644, 1.1997, 1.2231, 1.3, 1.3634, 1.4119, 1.4986, 1.5107, 1.6038, 1.6198, 1.7092, 1.7634, 1.8315, 1.8628, 1.8902, 1.9954]
y = [6.4807, 4.3908, 4.6809, 5.9789, 5.8868, 6.3358, 5.7539, 9.0586, 8.908, 10.861, 7.8247, 8.4379, 9.4756, 10.0429, 13.0431, 8.5154, 13.8963, 13.1907, 15.5389, 14.1556, 15.7486, 15.5616, 16.6609, 17.3241, 18.9491, 20.4458, 22.3217, 22.0497, 24.0743, 25.6398, 27.923, 28.9519, 31.4098, 32.3981, 30.4835, 34.7036]
values = [0.3824, 0.4525, 0.6148, 0.783, 0.977]


#linearização, transformando y em ln(y)
for i in range(0, len(y)):
    y[i] = log(y[i])

    

z, w = best_poly(x,y, 1) 

a = exp(z) # a função te retorna um valor z = ln(a), então isola a e obtém a = exp(z)
b = w/log(2) # a função te retorna um valor w = b * ln(2), então isola b e obtém b = w/log(2)
print('Coefs:\n',f'{a}, {b}', end=',')

def p(x, a, b):
	return a * pow(2, b*x) 

print()
print('Values:\n')
for value in values:
    print(f'{(p(value, a, b))}', end=", ")
print("")
