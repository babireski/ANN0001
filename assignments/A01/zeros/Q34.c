#include "methods.h"
#define lr 1.37
#define br 5.56
#define H 3.06
#define dt 438.23
#define dw 1000

double V(double h, double r) /* Calcula o volume do tronco de acordo com a variação da latura h e do raio maior r */
{
    return (pi * h / 3) * (pow(lr, 2) + pow(r, 2) + lr * r);
}

double mr(double h) /* Calcula o raio maior do tronco de acordo com a variação da altura h */
{
    return lr + ((br - lr) / H) * h;
}

double f(double h)
{
    return dt * V(H, br) - dw * (V(H, br) - V(h, mr(h)));
}

int main()
{
    int i[] = {2, 4, 8, 12};
    int j[] = {1, 2, 5};
    int k[] = {2, 4, 7, 11};

    bisection(f, 0, 3.06, i, 12);
    printf(",\n");
    secant(f, 0.28, 2.82, j, 5);
    printf(",\n");
    falsi(f, 0, 3.06, k, 11);

    return 0;
}