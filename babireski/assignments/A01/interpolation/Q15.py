from methods import *
from math import *

x = [-2.366, -1.155, 1.363, 3.696]
y = [3.072, 1.66, 1.642, 4.321]

print(*spline(x, y), sep = ',\n')