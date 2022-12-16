from methods import *
from math import *

# def f(x):
#     return sin(sqrt(1 + tan(x))) 

# def f(x):
#     return sin(x) ** 3 - 3 * sin(x) ** 2 + sin(x ** 2) + 4

def f(x):
    return cos(x) ** 3 + 2 * cos(x) ** 2

x = [-2.692, -1.809, -0.874, -0.16, 0.475, 1.697, 2.74, 3.362, 4.061]
values = [-0.09, 0.995, 3.384, 3.686, 4.45]

y = image(f, x)

p = polynomial(vandermonde(x, y))

print(*error(f, p, values), sep = ',\n')
