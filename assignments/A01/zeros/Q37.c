#include "methods.h"
#define w 15.23 
#define h 9.3

double f(double l)
{
    return (w - l - l) * (h - l - l) * l;
}

double df(double l)
{
    return 12 * pow(l, 2) + (-4 * w - 4 * h) * l + h * w;
}

double ddf(double l)
{
    return 4 * (6 * l - w - h);
}

int main()
{
    int i[] = {2, 4, 8, 12};
    int j[] = {1, 3, 5};
    int k[] = {1, 2, 5};
    int l[] = {2, 4, 7, 11};

    bisection(df, 0, 4.65, i, 12);
    printf(",\n");
    newton(df, ddf, 2.51, j, 5);
    printf(",\n");
    secant(df, 1.04, 3.92, k, 5);
    printf(",\n");
    falsi(df, 0, 4.65, l, 11);

    return 0;
}