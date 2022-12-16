from methods import *
from math import *

x = [0.272, 1.752, 3.239]
y = [0.636, 1.998, 0.139]

print(*lagrange(x, y), sep = ',\n')