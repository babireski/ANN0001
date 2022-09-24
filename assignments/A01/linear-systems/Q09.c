#include <stdio.h>
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
    double A[m][n] = {{5, 8, 6, -3}, {-2, 2, 3, 1}, {7, -4, -1, -7}, {-8, -5, -4, 6}};

    add(A, 2, 1, 2 / 5.0);
    add(A, 3, 1, -7 / 5.0);
    add(A, 4, 1, 8 / 5.0);
    add(A, 3, 2, 38 / 13.0);
    add(A, 4, 2, -3 / 2.0);
    add(A, 4, 3, 65 / 166.0);

    print(A);

    return 0;
}