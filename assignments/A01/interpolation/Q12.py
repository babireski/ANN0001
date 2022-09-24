from methods import *
from math import *

x = [1.69, 2.17, 2.708, 3.08, 3.557, 4.085, 4.891]
y = [-0.91, -0.963, -0.559, -0.132, 0.424, 0.868, 0.925]

print(*newton(x, y), sep = ',\n')