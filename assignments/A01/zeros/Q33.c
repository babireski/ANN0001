#include "methods.h"
#define r 1.15
#define ds 146.61
#define dw 1000

double vs()
{
    return 4 / 3 * pi * pow(r, 3);
}

double ve(double h)
{
    return pi * pow(h, 2) / 3 * (3 * r - h);
}

double f(double h)
{
    return dw * ((pow(r, 3) * 4 / 3) - (pow(h, 2)) * r + (pow(h, 3)) / 3) - ds * (4 * (pow(r, 3)) / 3);
}

double df(double h)
{
    return dw * (-2 * h * r + pow(h, 2));
}

int main()
{
    int i[] = {2, 4, 8, 12};
    int j[] = {1, 3, 5};
    int k[] = {1, 2, 5};
    int l[] = {2, 4, 7, 9};

    bisection(f, 0, 2.3, i, 12);
    printf(",\n");
    newton(f, df, 1.22, j, 5);
    printf(",\n");
    secant(f, 0.22, 2.11, k, 5);
    printf(",\n");
    falsi(f, 0, 2.3, l, 11);

    return 0;
}