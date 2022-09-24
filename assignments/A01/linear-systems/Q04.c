#include <stdbool.h>
#include <stdio.h>
#define rows 3
#define columns 3

void jacobi(double A[rows][columns], double B[rows], double X[rows], int iterations[], int n)
{
    double N[rows];
    int counter = 0;

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < rows; i++)
        {
            N[i] = B[i];

            for(int j = 0; j < columns; j++)
            {
                if(i != j)
                {
                    N[i] = N[i] - A[i][j] * X[j];   
                }
            }

            N[i] = N[i] / A[i][i];
        }

        for(int i = 0; i < rows; i++)
        {
            X[i] = N[i];
        }

        if(k + 1 == iterations[counter])
        {
            if(counter) printf(",\n");

            for(int i = 0; i < rows; i++)
            {
                if(i) printf(", ");
                printf("%.16f", X[i]);
            }

            counter++;
        }
    }
}

int main()
{
    double A[rows][columns] =
    {
        {-7.67, 3.28, 3.2},
        {0.02, -1.37, -0.15},
        {-1.13, -0.32, 2.64}    
    };

    double B[] = {-2.51, -0.82, 0.19};
    double X[] = {-3.68, -4.2, -4.84};
    int iterations[] = {1, 5, 6, 7, 10, 12, 17, 19};

    jacobi(A, B, X, iterations, iterations[sizeof(iterations) / sizeof(int) - 1]);
}