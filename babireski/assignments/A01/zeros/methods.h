#include <stdio.h>
#include <math.h>
#define pi 3.14159265358979323846
#define g 9.81

double root(double (*f)(double), double xo, double xa)
{
    return (xo * f(xa) - xa * f(xo)) / (f(xa) - f(xo));
}

void bisection(double(*f)(double), double a, double b, int *iterations, int n)
{
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

void newton(double (*f)(double), double (*df)(double), double xo, int *iterations, int n)
{
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

void secant(double (*f)(double), double xo, double xa, int *iterations, int n)
{
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

void falsi(double (*f)(double), double a, double b, int *iterations, int n)
{
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

void fixed(double (*f)(double), double xo, int *iterations, int n)
{
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