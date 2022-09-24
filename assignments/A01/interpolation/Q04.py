from methods import *
from math import *

def f(x):
    return sin(sqrt(1 + tan(x)))

def g(x):
    return cos(x) ** 3 + 2 * cos(x) ** 2 + 1

def h(x):
    return cos(x + sqrt(log(x ** 2)))

xf = [3.008, 3.833, 4.228]
yf = []

for x in xf:
    yf.append(f(x))

xg = [-2.442, -1.362, -0.669, 0.134, 0.947, 2.194, 2.79, 4.391]
yg = []

for x in xg:
    yg.append(g(x))

xh = [1.567, 1.919, 2.125, 2.555, 2.742, 3.232, 3.548, 3.81, 4.276, 4.382, 4.736]
yh = []

for x in xh:
    yh.append(h(x))

print(*vandermonde(xh, yh), sep = ",\n")