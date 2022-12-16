import math

def newton(f, df, xo, n):
    for _ in range(n):
        xo = xo - f(xo) / df(xo)
        yield xo

def f(x):
    return 1161920 * math.exp(x) + (109945 / x) * (math.exp(x) - 1) - 2183290

def df(x):
    return (5 * (math.exp(x) * (x * (232384 * x + 21989) - 21989) + 21989)) / (x ** 2)

iterations = [1, 3, 5]
xo = 1.26
n = 5

results = list(newton(f, df, xo, n))
selection = []

for i in iterations:
    selection.append(results[i - 1])

print(*selection, sep = ",\n")