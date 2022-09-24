#include <stdio.h>
#include <math.h>

void newton(double (*f)(double), double (*df)(double), double xo, int n)
{
    int iterations[] = {1, 3, 5};
    int k = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (df(xo) == 0)
        {
            break;
        }

        double xi = xo - f(xo) / df(xo);

        if (i + 1 == iterations[k])
        {
            if(k)
            {
                printf(",\n");
            }

            printf("%.16f", xi);
            k++;
        }

        xo = xi;
    }
}

double f(double x)
{
    return sqrt(2 * 9.81 * x) * tanh(sqrt(2 * 9.81 * x) / (2 * 9.46) * 5.56) - 8.55;
}

double df(double x)
{
    return 2.88285 * pow(1/cosh(1.30168 * sqrt(x)),2) + (2.21472 * tanh(1.30168 * sqrt(x)))/sqrt(x);
}

int main()
{
    double xo = 0.16;
    int n = 5;

    newton(f, df, xo, n);

    return 0;
}