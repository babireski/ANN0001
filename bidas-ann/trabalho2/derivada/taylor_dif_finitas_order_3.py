from methods import *

# x0 = ponto onde a função será derivada
# x = lista de coordenadas na proximidade de x0
# y = cálculo da função em todos os pontos x
# k = ordem da derivada

def f(x):
    return 3 * math.cos((x**2-1)**(1/3))

x0 = 7.28
x = [7.0367, 7.1623, 7.2432, 7.3345, 7.4412, 7.4538]
values = [7.1705, 7.237, 7.4447]

def p(x0, x, xp):
    y = [f(xi) for xi in x]

    coeffs = coeffs_dif_fin(x0, x, 1)
    f_1 = dif_fin(coeffs, y)

    coeffs = coeffs_dif_fin(x0, x, 2)
    f_2 = dif_fin(coeffs, y)

    coeffs = coeffs_dif_fin(x0, x, 3)
    f_3 = dif_fin(coeffs, y)

    return f(x0) + f_1*(xp - x0) + (f_2/2)*((xp - x0)**2) + (f_3/6)*((xp - x0)**3) 

px = [p(x0, x, vi) for vi in values]
print(f'{px = }')

fx_menos_px = [np.abs(f(vi) - p(x0, x, vi)) for vi in values]
print(f'{fx_menos_px = }')

print("")
print(*printLists(px, fx_menos_px), sep=", ")
