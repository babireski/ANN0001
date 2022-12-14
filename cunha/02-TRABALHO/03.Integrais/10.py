'''A seguinte lista de 45 pontos
(0.174,1.809), (0.4415,2.654), (0.709,2.995), (0.748,3.0), (0.787,2.995), (1.0445,2.791),
(1.302,2.468), (1.4105,2.341), (1.519,2.229), (1.655,2.119), (1.791,2.044), (2.0105,2.0),
(2.23,2.053), (2.2365,2.056), (2.243,2.059), (2.361,2.13), (2.479,2.227), (2.56,2.308),
(2.641,2.399), (2.647,2.406), (2.653,2.414), (2.676,2.441), (2.699,2.469), (2.875,2.693), 
(3.051,2.893), (3.077,2.917), (3.103,2.938), (3.13,2.957), (3.157,2.973), (3.1625,2.976), 
(3.168,2.979), (3.365,2.958), (3.562,2.646), (3.5735,2.618), (3.585,2.589), (3.669,2.349), 
(3.753,2.069), (3.842,1.751), (3.931,1.446), (3.9765,1.307), (4.022,1.188), (4.434,1.649), 
(4.846,2.97), (4.858,2.951) e (4.87,2.928)
vive no gráfico de uma função f. Use a regra de Simpson para aproximar a área 
embaixo do gráfico de f no intervalo [0.174,4.87].'''

def simps(f, a, b, n):
    if n % 2 != 0 or n < 1:
        raise ValueError("n deve ser par e maior q 1")
    h = (b - a) / n
    soma_odd, soma_even = 0, 0
    for k in range(1,n,2):
        soma_odd += f(a+k*h)
    for k in range(2,n,2):
        soma_even += f(a + k * h)
    return (h/3) * (f(a) + 4 * soma_odd + 2 * soma_even + f(b))

def simp(x0,x1,x3,y0,y1,y2):
    return ((x1-x0)/3)*(y0+4*y1+y2)

def simpsPonto(x, y):
    tam = (len(x) - 1) // 2
    somas = 0
    k = 0
    for i in range(tam):
        somas += simp(x[k],x[k+1],x[k+2],y[k],y[k+1],y[k+2])
        k += 2
    print(f'{somas}')

x = [0.174, 0.4415, 0.709, 0.748, 0.787, 1.0445, 1.302, 1.4105, 1.519, 1.655, 1.791, 2.0105, 2.23, 2.2365, 2.243, 2.361, 2.479, 2.56, 2.641, 2.647, 2.653, 2.676, 2.699, 2.875, 3.051, 3.077, 3.103, 3.13, 3.157, 3.1625, 3.168, 3.365, 3.562, 3.5735, 3.585, 3.669, 3.753, 3.842, 3.931, 3.9765, 4.022, 4.434, 4.846, 4.858, 4.87]
y = [1.809, 2.654, 2.995, 3.0, 2.995, 2.791, 2.468, 2.341, 2.229, 2.119, 2.044, 2.0, 2.053, 2.056, 2.059, 2.13, 2.227, 2.308, 2.399, 2.406, 2.414, 2.441, 2.469, 2.693, 2.893, 2.917, 2.938, 2.957, 2.973, 2.976, 2.979, 2.958, 2.646, 2.618, 2.589, 2.349, 2.069, 1.751, 1.446, 1.307, 1.188, 1.649, 2.97, 2.951, 2.928]

simpsPonto(x, y)