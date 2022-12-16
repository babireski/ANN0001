import numpy

def vandermonde(x, y):
    A = []
    B = y
    for e in x:
        row = [1] + [e ** k for k in range(1, len(x))]
        A.append(row)
    coefficients = numpy.linalg.solve(A, B)
    return coefficients

def interpolation(coefficients):
    def function(x):
        sum = coefficients[0]
        for i, c in enumerate(coefficients[1:], 1):
            sum += c * x ** i
        return sum
    return function

if __name__ == '__main__':
    import matplotlib.pyplot as plot

    x = [1,  3]
    y = [2, -1]

    coefficients = vandermonde(x, y)
    print(coefficients)

    p = interpolation(coefficients)
    print(f'{p(1) = } e {p(3) = }')

    t = numpy.linspace(-1, 4, 100)
    pt = [p(ti) for ti in t]

    plot.plot(t, pt, color = 'red')
    plot.scatter(x, y, color = 'blue')
    plot.savefig('interpolation.png')