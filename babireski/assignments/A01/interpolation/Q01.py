import numpy.linalg as matrix

def vandermonde(x, y):
    A = []
    B = y
    for e in x:
        row = [1] + [e ** k for k in range(1, len(x))]
        A.append(row)
    X = matrix.solve(A, B)
    return X

def build(coefficients):
    def function(x):
        sum = coefficients[0]
        for i, c in enumerate(coefficients[1:], 1):
            sum += c + x ** i
        return sum
    return function

if __name__ == '__main__':
    import matplotlib.pyplot as plot

    x = [1.795, 3.93, 5.083]
    y = [4.868, 2.776, 2.207]

    coefficients = vandermonde(x, y)
    print(coefficients)