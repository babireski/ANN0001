from methods import *
from math import *

# def f(x):
#     return 1 / (1 + 25 * x ** 2)

# def f(x):
#     return cos(x) ** 3 + 2 * cos(x) ** 2 + 1

def f(x):
    return cos(x + sqrt(log(x ** 2)))

x = [1.505, 1.696, 1.907, 2.325, 2.429, 2.792, 2.948, 3.173, 3.515, 3.756, 3.847, 4.09, 4.433, 4.57, 4.797]
y = image(f, x)

print(*newton(x, y), sep = ',\n')