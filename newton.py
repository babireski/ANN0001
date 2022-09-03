import math

def newton(f, df, xo, n):
    for _ in range(n):
        xo = xo - f(xo) / df(xo)
        yield xo

def f(x):
    return x * (x - 1) * (x - 2) + 0.42

def df(x):
    return 3 * x ** 2 - 6 * x + 2

xo = 2.31658864
n = 200

results = list(newton(f, df, xo, n))

iterations = [5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175, 180, 185, 190, 195]

for i in iterations:
    print(results[i - 1], ",")