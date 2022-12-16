#include <stdio.h>
#define m 4
#define n 5

void print(double E[m][n])
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j)
            {
                printf(", ");
            }

            printf("%.16f", E[i][j]);
        }

        if(i + 1 < m)
        {
            printf(", ");
        }

        printf("\n");
    }
}

void swap(double E[m][n], int r, int s)
{
    double auxiliary;

    for(int j = 0; j < n; j++)
    {
        auxiliary = E[r - 1][j];
        E[r - 1][j] = E[s - 1][j];
        E[s - 1][j] = auxiliary;
    }
}

void multiply(double E[m][n], int r, double k)
{
    if(k)
    {
        for(int j = 0; j < n; j++)
        {
            E[r - 1][j] *= k; 
        }
    }
}

void add(double E[m][n], int r, int s, double k)
{
    if(r != s)
    {
        for(int j = 0; j < n; j++)
        {
            E[r - 1][j] += E[s - 1][j] * k;
        }
    }
}