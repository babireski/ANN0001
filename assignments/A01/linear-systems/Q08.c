#include <stdio.h>
#define m 3
#define n 3

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

            printf("%.16f", A[i][j]);
        }

        if(i + 1 < m)
        {
            printf(", ");
        }

        printf("\n");
    }
}

void swap(double A[m][n], int r, int s)
{
    double auxiliary;

    for(int j = 0; j < n; j++)
    {
        auxiliary = A[r - 1][j];
        A[r - 1][j] = A[s - 1][j];
        A[s - 1][j] = auxiliary;
    }
}

void multiply(double A[m][n], int r, double k)
{
    if(k)
    {
        for(int j = 0; j < n; j++)
        {
            A[r - 1][j] *= k; 
        }
    }
}

void add(double A[m][n], int r, int s, double k)
{
    if(r != s)
    {
        for(int j = 0; j < n; j++)
        {
            A[r - 1][j] = A[r - 1][j] + A[s - 1][j] * k;
        }
    }
}

int main()
{
    double A[m][n] = {{-5, -2, -5}, {-6, -2, 6}, {5, -1, -3}};

    add(A, 2, 1, -6 / 5.0);
    add(A, 3, 1, 1);
    add(A, 3, 2, 15 / 2.0);

    print(A);

    return 0;
}