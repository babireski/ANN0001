#include <stdio.h>
#include <math.h>

void bisection(double(*f)(double), double a, double b, int n)
{
    int iterations[] = {2, 4, 8, 12};
    int k = 0;

    if(f(a) * f(b) > 0)
    {
        printf("Invalid interval!");
        return;
    }

    else
    {
        for(int i = 0; i < n; i++)
        {
            double m = 0.5 * (a + b);

            if(f(m) == 0)
            {
                printf("Root founded!");
                printf("%.16f,\n", m);
                return;
            }

            if(iterations[k] == i + 1)
            {
                if(k)
                {
                    printf(",\n");
                }

                printf("%.16f", m);
                k++;
            }

            if(f(a) * f(m) < 0)
            {
                b = m;
            }

            else
            {
                a = m;
            }
        }
    }
}

double f(double x)
{
    return sqrt(2 * 9.81 * x) * tanh(sqrt(2 * 9.81 * x) / (2 * 9.46) * 5.56) - 8.55;
}

int main()
{
    double a = 0.4;
    double b = 19.71;
    int n = 12;

    bisection(f, a, b, n);

    return 0;
}