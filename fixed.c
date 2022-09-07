#include <stdio.h>
#include <math.h>

void fixed(double (*f)(double), double xo, int n)
{
    int iterations[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 0;

    for(int i = 0; i < n; i++)
    {
        double xi = f(xo);

        if(iterations[k] == i + 1)
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
    return  ((3 * pow(x, 4) + 2 * pow(x, 2) + 3) / (4 * pow(x, 3) + 4 * x - 1));
}

void main()
{
    double xo = 1.3663;
    int n = 10;

    fixed(f, xo, n);
}