#include "methods.h"
#define x 1.26
#define t 1.04 

double f(double omega)
{
    return -(g / (2 * pow(omega, 2))) * (sinh(omega * t) - sin(omega * t)) - x;
}

double df(double omega)
{
    return (g * (sinh(t * omega) - sin(t * omega))) / pow(omega, 3) - (g * (t * cosh(t * omega) - t * cos(t * omega))) / (2 * pow(omega, 2));
}

int main()
{
    int i[] = {2, 4, 8, 12};
    int j[] = {1, 3, 5};
    int k[] = {1, 2, 5};
    int l[] = {2, 4, 7, 11};

    bisection(f, -5.1, 0.12, i, 12);
    printf(",\n");
    newton(f, df, -1.14, j, 5);
    printf(",\n");
    secant(f, -4.88, -1.45, k, 5);
    printf(",\n");
    falsi(f, -5.06, 0.3, l, 11);

    return 0;
}