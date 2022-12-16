def lagrange(x, y):
    coefficients = []
    for i in range(len(x)):
        product = 1
        for j in range(len(x)):
            if i != j:
                product *= x[i] - x[j]
        ci = y[i] / product
        coefficients.append(ci)
    return coefficients