from methods import *
from math import *

def s(x):
    for key, value in coefficients.items():
        if value['domain'][0] <= x <= value['domain'][1]:
            return eval(value['eq'])

x = [0.373, 0.827, 1.629, 1.981, 2.441, 3.219, 3.893, 4.291, 5.068, 5.67, 6.287, 6.789]
y = [5.107, 4.288, 3.621, 3.352, 2.974, 2.098, 2.515, 3.108, 3.936, 4.775, 4.486, 4.874]
values = [1.637, 2.35, 3.825, 5.104, 5.187]
coefficients = spline(x, y)

# print(coefficients)

for i, x in enumerate(values):
    if i:
        print(",")
    print(s(x), end = '')