#include <stdio.h>
#include <math.h>

void false(double (*f)(double), double a, double b, int n)
{
    int iterations[] = {2, 4, 7, 11};
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
    return sqrt(2 * 9.81 * x) * tanh(sqrt(2 * 9.81 * x) / (2 * 9.46) * 5.56) - 8.55;
}

int main()
{
    double a = 0.07;
    double b = 16.52;
    int n = 11;

    false(f, a, b, n);

    return 0;
}