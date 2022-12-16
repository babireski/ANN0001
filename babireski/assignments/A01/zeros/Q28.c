#include "methods.h"
#define c 28.20
#define v 37.25
#define t 7.39

double f(double m)
{
    return (g * m) / c * (1 - exp(-(c / m) * t)) - v;
}

double df(double m)
{
    return (g*  (1 - exp( - (c * t) / m))) / c - (g * t * exp(- (c * t) / m)) / m;
}

int main()
{
    int i[] = {2, 4, 8, 12};
    int j[] = {1, 3, 5};
    int k[] = {1, 2, 5};
    int l[] = {2, 4, 7, 11};

    bisection(f, 25.63, 186.33, i, 12);
    printf(",\n");
    newton(f, df, 27.76, j, 5);
    printf(",\n");
    secant(f, 24.84, 37.84, k, 5);
    printf(",\n");
    falsi(f, 33.79, 183.11, l, 11);

    return 0;
}