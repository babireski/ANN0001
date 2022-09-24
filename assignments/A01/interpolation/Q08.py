from methods import *
from math import *

x = [2.645, 2.993, 3.149, 3.548, 3.725, 3.948, 4.276, 4.455]
y = [0.626, 0.797, 0.843, 0.931, 0.96, 0.99, 0.98, 0.814]

print(*lagrange(x, y), sep = ',\n')