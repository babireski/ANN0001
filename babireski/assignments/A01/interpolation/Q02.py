import numpy.linalg as matrix

def vandermonde(x, y):
    A = []
    B = y
    for e in x:
        row = [1] + [e ** k for k in range(1, len(x))]
        A.append(row)
    X = matrix.solve(A, B)
    return X

if __name__ == '__main__':
    import matplotlib.pyplot as plot

    x = [0.597, 1.122, 2.269, 3.305, 4.24, 5.119, 6.668]
    y = [4.55, 4.859, 4.594, 3.473, 2.51, 2.208, 2.893]

    coefficients = vandermonde(x, y)
    print(coefficients)