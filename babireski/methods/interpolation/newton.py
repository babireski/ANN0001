def newton(x, y):
	Y = [yi for yi in y]
	coefficients = [y[0]]
	for j in range(len(x) -1):
		for i in range(len(x) - j - i):
			numerator = Y[i + 1] - Y[i]
			denominator = x[i + j + i] - x[i]
			division = numerator / denominator
			Y[i] = division
		coefficients.append(Y[0])
	return coefficients