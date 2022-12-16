#include <stdio.h>
#include <math.h>
#define m 4
#define n 4

void print(double A[m][n])
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j)
            {
                printf(", ");
            }

            printf("%.9f", A[i][j]);
        }

        if(i + 1 < m)
        {
            printf(",\t");
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

void gauss(double E[m][n]) /* Para sistemas n por n */
{
    for(int j = 0; j < n - 1; j++)
    {
        for(int i = j; i < m; i++)
        {
            if(E[i][j] == 0 && i < m - 1)
            {
                int k = i;

                while(E[k][j] == 0 && k < m - 1)
                {
                    swap(E, i + 1, i + 2);
                }
            }

            if(E[i][j] != 0)
            {
                multiply(E, i + 1, 1 / E[i][j]);

                for(int k = 0; k < m; k++)
                {
                    if(k != i)
                    {
                        add(E, k + 1, i + 1, -E[k][j]);
                    }
                }

                break;
            }
        }
    }
}

int main()
{
    double K1 = 74;
    double K2 = 68;
    double K3 = 61;
    double K4 = 67;
    double K5 = 16;

    double E[m][n] =
    {
        {1, 1, 0, K1},
        {0, 1, 1, K2},
        {0, 0, 1, K3 - K5},
        {1, 0, 0, K4 - K5},
    };

    gauss(E);
    print(E);

    return 0;
}