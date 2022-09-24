#include "methods.h"
#define V 39.68
#define L 9.29
#define r 2.93

double f(double h)
{
    return L * (0.5 * pi * pow(r, 2) - pow(r, 2) * asin(h / r) - h * sqrt(pow(r, 2) - pow(h, 2))) - V;
}

int main()
{
    int i[] = {2, 4, 8, 12};
    int j[] = {1, 2, 5};
    int k[] = {2, 4, 7, 11};

    bisection(f, 0, 2.93, i, 12);
    printf(",\n");
    secant(f, 0.41, 2.66, j, 5);
    printf(",\n");
    falsi(f, 0, 2.93, k, 11);

    return 0;
}