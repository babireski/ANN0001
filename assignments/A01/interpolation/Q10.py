from methods import *
from math import *

# def f(x):
#     return exp(cos(x) ** 2) + exp(-x ** 2) + log(x)

# def f(x):
#     return 4 + sin(x) - x ** 2 / 30

def f(x):
    return exp(-x ** 2) + cos(x) + 3

x = [0.344, 0.725, 1.317, 1.948, 2.407, 2.815, 3.598, 3.932, 4.673, 5.245, 5.624, 6.104, 6.906]
y = image(f, x)

print(*lagrange(x, y), sep = ',\n') 