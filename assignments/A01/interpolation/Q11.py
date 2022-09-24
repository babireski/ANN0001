from methods import *
from math import *

x = [0.544, 1.681, 2.858]
y = [0.591, 0.651, 0.65]

print(*newton(x, y), sep = ',\n')