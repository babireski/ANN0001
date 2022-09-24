import math

def secant(f, xo, xa, n):
    for _ in range(n):
        xb = root(xo, xa)
        yield xb
        xo = xa
        xa = xb

def root(xo, xa):
    return (xo * f(xa) - xa * f(xo)) / (f(xa) - f(xo))

def f(x): 
    return 1161920 * math.exp(x) + (109945 / x) * (math.exp(x) - 1) - 2183290

iterations = [1, 2, 5]
xo = 0.10
xa = 1.73
n = 5

results = list(secant(f, xo, xa, n))
selection = []

for i in iterations:
    selection.append(results[i - 1])

print(*selection, sep = ",\n")