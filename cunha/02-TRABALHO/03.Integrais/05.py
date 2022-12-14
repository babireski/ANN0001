"""A seguinte lista de 47 pontos
(0.038,1.35), (0.107,1.572), (0.331,2.349), (0.386,2.511), (0.412,2.581), (0.422,2.606), 
(0.577,2.899), (0.832,2.979), (0.892,2.942), (1.004,2.837), (1.074,2.756), (1.161,2.647), 
(1.226,2.564), (1.234,2.554), (1.368,2.389), (1.464,2.283), (1.546,2.205), (1.753,2.061), 
(2.11,2.012), (2.479,2.227), (2.547,2.295), (2.626,2.382), (2.703,2.474), (2.774,2.564), 
(2.794,2.589), (2.821,2.624), (2.846,2.656), (3.013,2.855), (3.105,2.939), (3.299,2.993), 
(3.342,2.974), (3.348,2.97), (3.514,2.751), (3.575,2.614), (3.726,2.162), (3.744,2.1), 
(3.894,1.569), (3.937,1.427), (3.972,1.32), (4.188,1.003), (4.191,1.004), (4.325,1.231), 
(4.377,1.408), (4.753,2.962), (4.8,3.0), (4.824,2.993) e (4.86,2.947)
vive no gráfico de uma função f. Use a regra dos trapézios para aproximar a área embaixo do 
gráfico de f no intervalo [0.038,4.86]"""

x = [0.038, 0.107, 0.331, 0.386, 0.412, 0.422, 0.577, 0.832, 0.892, 1.004, 1.074, 1.161, 1.226, 1.234, 1.368, 1.464, 1.546, 1.753, 2.11, 2.479, 2.547, 2.626, 2.703, 2.774, 2.794, 2.821, 2.846, 3.013, 3.105, 3.299, 3.342, 3.348, 3.514, 3.575, 3.726, 3.744, 3.894, 3.937, 3.972, 4.188, 4.191, 4.325, 4.377, 4.753, 4.8, 4.824, 4.86]
y = [1.35, 1.572, 2.349, 2.511, 2.581, 2.606, 2.899, 2.979, 2.942, 2.837, 2.756, 2.647, 2.564, 2.554, 2.389, 2.283, 2.205, 2.061, 2.012, 2.227, 2.295, 2.382, 2.474, 2.564, 2.589, 2.624, 2.656, 2.855, 2.939, 2.993, 2.974, 2.97, 2.751, 2.614, 2.162, 2.1, 1.569, 1.427, 1.32, 1.003, 1.004, 1.231, 1.408, 2.962, 3.0, 2.993, 2.947]
soma = 0
xy = zip(x, y)

for a2, b2 in zip(x[1:], y[1:]):  # lista de x e y removidos os primeiros elementos
    for a1, b1 in zip(x, y):
        soma += ((a2-a1) * (b2 + b1))/2.0
        x.pop(0)  # removendo os primeiros elementos das listas de x e y
        y.pop(0)
        break

print('A soma das áreas: ', soma)