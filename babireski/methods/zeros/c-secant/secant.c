#include <stdio.h>
#include <math.h>

double root(double (*f)(double), double xo, double xa)
{
    return (xo * f(xa) - xa * f(xo)) / (f(xa) - f(xo));
}

void secant(double (*f)(double), double xo, double xa, int n)
{
    int iterations[] = {1, 2, 5};
    int k = 0;

    for(int i = 0; i < n; i++)
    {
        if(f(xo) == f(xa))
        {
            return; 
        }

        double xb = root(f, xo, xa);

        if(iterations[k] == i + 1)
        {
            if(k)
            {
                printf(",\n");
            }

            printf("%.16f", xb);
            k++;
        }

        xo = xa;
        xa = xb;
    }
}

double f(double x)
{
    return sqrt(2 * 9.81 * x) * tanh(sqrt(2 * 9.81 * x) / (2 * 8.85) * 7.83) - 10.03;
}

int main()
{
    double xo = 0.6;
    double xa = 18.02;
    int n = 5;

    secant(f, xo, xa, n);

    return 0;
}