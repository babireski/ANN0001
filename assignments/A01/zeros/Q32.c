#include "methods.h"
#define R 7.92
#define V 1643.62

double f(double h)
{
    return pi * pow(h, 2) * ((3 * R - h) / 3) - V;
}

double df(double h)
{
    return -pi * h * (h - 2 * R);
}

int main()
{
    int i[] = {2, 4, 8, 12};
    int j[] = {1, 3, 5};
    int k[] = {1, 2, 5};
    int l[] = {2, 5, 7, 11};

    bisection(f, 0, 15.84, i, 12);
    printf(",\n");
    newton(f, df, 4.12, j, 5);
    printf(",\n");
    secant(f, 0.7, 12.24, k, 5);
    printf(",\n");
    falsi(f, 0, 15.84, l, 11);

    return 0;
}