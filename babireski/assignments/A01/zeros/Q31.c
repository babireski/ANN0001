#include "methods.h"
#define Q 51.46

double A(double y)
{
    return 2.04 * y + ((pow(y, 2) / 2));
}

double B(double y)
{
    return 2.04 + y;
}

double f(double y)
{
    return 1 - (pow(Q, 2) / (g * pow(A(y), 3)) * B(y));
}

int main()
{
    int a[] = {2, 4, 8, 12};
    int b[] = {2, 4, 7, 11};

    bisection(f, 0.89, 8.61, a, 12);
    printf(",\n");
    falsi(f, 0.27, 9.99, b, 11);

    return 0;
}