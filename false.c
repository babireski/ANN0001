#include <stdio.h>
#include <math.h>

void false(double (*f)(double), double a, double b, int n)
{
    int iterations[] = {1 , 25, 50, 100, 200, 400, 800, 1600, 3200, 4800, 6400, 8000, 10000};
    int k = 0;

    for(int i = 0; i < n; i++)
    {
        if(!(f(a) * f(b) < 0))
        {
            printf("Invalid interval!");
            break;
        }

        double xi = (a * f(b) - b * f(a)) / (f(b) - f(a));

        if(iterations[k] == i + 1)
        {
            if(k)
            {
                printf(",\n");
            }

            printf("%.16f", xi);
            k++;
        }

        if(f(a) * f(xi) < 0)
        {
            b = xi;
        }

        else
        {
            a = xi;
        }
    }
}

double f(double x)
{
    return exp(5 * x) - 2;
}

void main()
{
    double a = -0.9400461;
    double b = 1.9703559;
    int n = 10000;

    secant(f, a, b, n);
}