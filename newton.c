#include <stdio.h>
#include <math.h>

void newton(double (*f)(double), double (*df)(double), double xo, int n)
{
    int iterations[] = {1, 25, 50, 100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700};
    int j = 0;
    
    for (int i = 0; i < n; i++)
    {

        if (df(xo) == 0)
        {
            break;
        }

        double xi = xo - f(xo) / df(xo);
        // printf("x_%i = %.16f\n", i + 1, xi);

        if (i + 1 == iterations[j])
        {
            printf("%.16f,\n", xi);
            j++;
        }

        xo = xi;
    }
}

void main()
{
    double f(double x)
    {
        return exp(5 * x) - 2;
    }

    double df(double x)
    {
        return 5 * exp(5 * x);
    }

    double xo = -1.16391525;
    int n = 800;

    newton(f, df, xo, n);
}