from methods import *

def f(x):
    return x**2 * math.cos(x - 1) * math.exp(-3 * x ** 2)

x0 = 0.1533
order = 5
x = [-0.0504, -0.012, 0.0354, 0.0954, 0.1154, 0.1549, 0.2345, 0.255, 0.3434, 0.3587]
values = [0.0143, 0.0438, 0.104, 0.1931, 0.3046]

order1 = 1
order2 = 2
order3 = 3
order4 = 4
order5 = 5

p = 0
n = len(values)
for i in range(n):
    p = f(x0) + finite_diffs(x, order1, x0, f)*(values[i] - x0) + ((finite_diffs(x, order2, x0, f)/2) * ((values[i]-x0)**2)) + ((finite_diffs(x, order3, x0, f)/6) * ((values[i]-x0)**3)) + ((finite_diffs(x, order4, x0, f)/24) * ((values[i]-x0)**4)) + ((finite_diffs(x, order, x0, f)/120) * ((values[i]-x0)**5)) 
    erroN = math.sqrt(((f(values[i]) - p)**2))
    print(f'{p}, {erroN}', end=", ")
print("")
