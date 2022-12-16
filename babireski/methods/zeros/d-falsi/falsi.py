import math

def false(f, a, b, n):
    for _ in range(n):
        xi = (a * f(b) - b * f(a)) / (f(b) - f(a))
        
        yield xi

        if f(a) * f(xi) < 0:
            b = xi

        else:
            a = xi

def f(x):
    return 1161920 * math.exp(x) + (109945 / x) * (math.exp(x) - 1) - 2183290

iterations = [2, 4, 7, 11]
a = 0,10
b = 1.76
n = 11

results = list(false(f, a, b, n))