import math

def bisection(f, a, b, n):
    for _ in range(n):
        m = 0.5 * (a + b)
        yield m
        if f(a) * f(m) < 0:
            b = m
        else:
            a = m

def f(x):
    return 1161920 * math.exp(x) + (109945 / x) * (math.exp(x) - 1) - 2183290

iterations = [2, 4, 8, 12]
a = 0.10
b = 1.28
n = 12

results = list(bisection(f, a, b, n))
selection = []

for i in iterations:
    selection.append(results[i - 1])

print(*selection, sep = ",\n")