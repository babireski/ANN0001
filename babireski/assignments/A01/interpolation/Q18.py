from methods import *
from math import *

# def f(x):
#     return x ** 5 - 4 * x ** 2 + 2 * sqrt(x + 1) + cos(x)

# def f(x):
#     return exp(cos(x) ** 2) + exp(-x ** 2) + log(x)

def f(x):
    return 1 / (1 + 25 * x ** 2)

x = [-0.851, -0.793, -0.521, -0.43, -0.226, -0.094, 0.076, 0.184, 0.383, 0.571, 0.781, 0.961]
y = image(f, x)

print(*spline(x, y), sep = ',\n')