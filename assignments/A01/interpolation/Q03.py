import numpy

def vandermonde(x, y):
    A = []
    B = y
    for e in x:
        row = [1] + [e ** k for k in range(1, len(x))]
        A.append(row)
    X = numpy.linalg.solve(A, B)
    return X

if __name__ == '__main__':
    import matplotlib.pyplot as plot

    x = [0.067, 0.886, 1.634, 2.005, 2.527, 3.217, 3.72, 4.444, 4.967, 5.533, 6.215, 6.893]
    y = [4.067, 4.748, 4.909, 4.773, 4.364, 3.58, 2.992, 2.377, 2.21, 2.298, 2.644, 2.989]

    coefficients = vandermonde(x, y)
    for coefficient in (coefficients):
        print("%.16f," %coefficient)

    