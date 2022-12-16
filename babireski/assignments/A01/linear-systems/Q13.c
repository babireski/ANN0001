#include <stdio.h>
#include <math.h>
#define M1 77.97
#define M2 65.24
#define M3 51.92
#define C1 8.76
#define C2 15.32
#define C3 18.43
#define G 9.81
#define V 7.38
#define m 3
#define n 4

/*
    P1 → M1 * G - T - C1 * V = M1 * A
    P2 → M2 * G + T - R - C2 * V = M2 * A
    P3 → M3 * G + R - C3 * V = M3 * A

    M1, 0, -1, C1 * V - M1 * G
    M2, -1, 1, C2 * V - M2 * G
    M3, 1, 0, C3 * V - M3 * G
*/

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
    double E[m][n] =
    {
        {M1,  0, -1, C1 * V - M1 * G},
        {M2, -1,  1, C2 * V - M2 * G},
        {M3,  1,  0, C3 * V - M3 * G}
    };

    gauss(E);
    print(E);

    return 0;
}