#include <stdio.h>
#include <math.h>

int main()
{
    double f(double x, double y)
    {
        return pow(x, 2) + 2 * pow(y, 2) - 3;
    }

    double g(double x, double y)
    {
        return 4 * pow(x, 2) + pow(y, 2) - 6;
    }

    double fx(double x, double y)
    {
        return 2 * x;
    }

    double fy(double x, double y)
    {
        return 4 * y;
    }

    double gx(double x, double y)
    {
        return 8 * x;
    }

    double gy(double x, double y)
    {
        return 2 * y;
    }

    int n = 5;
    double xo = 0.6833;
    double yo = -1.4783;

    // newton
    for (int i = 0; i < n; i++)
    {
        // jacobiano
        //[fx fy]
        //[gx gy]
        // inversa, antes de 1 / det
       // [gy -fy] [f1]
       // [-gx fx] [f2]

       double a = fx(xo, yo);
       double b = fy(xo, yo);
       double c = gx(xo, yo);
       double d = gy(xo, yo);
       double det = a * d - b * c;
       double xk = xo - (gy(xo, yo) * f(xo, yo) -fy(xo, yo) * g(xo, yo)) / det;
       double yk = yo - (-gx(xo, yo) * f(xo, yo) + fx(xo, yo) * g(xo, yo)) / det;
       xo = xk;
       yo = yk;

       printf("%.12f, %.12f,\n", xo, yo);
    }
}