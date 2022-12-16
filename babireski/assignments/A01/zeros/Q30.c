#include "methods.h"
#define L 5.08
#define t 7.18
#define v 11.96

double sech(double x)
{
    return 1 / cosh(x);
}

double f(double H)
{
    return sqrt(2 * g * H) * tanh(sqrt(2 * g * H) / (2 * L) * t) - v;
}

double df(double H)
{
    return (g * tanh((t * sqrt(g * H)) / (sqrt(2) * L))) / (sqrt(2) * sqrt(g * H)) + (g * t * pow(sech((t * sqrt(g * H)) / (sqrt(2) * L)), 2)) / (2 * L);
}

int main()
{
    int i[] = {2, 4, 8, 12};
    bisection(f, 0.17, 15.92, i, 12);
    printf(",\n");

    int j[] = {1, 3 , 5};
    newton(f, df, 0.93, j, 5);
    printf(",\n");

    int k[] = {2, 4, 7, 11};
    falsi(f, 0.08, 16.01, k, 11);

    return 0;
}