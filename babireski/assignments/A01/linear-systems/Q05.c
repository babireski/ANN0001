#include <stdbool.h>
#include <stdio.h>
#define rows 4
#define columns 4

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
        {8.47, 1.91, 4.4, -0.94},
        {-1.64, -9.4, -2.9, -3.66},
        {3.4, 4.96, 11.74, 2.17},
        {1.0, 3.35, 1.93, -7.49}
    };

    double B[] = {-3.74, 0.72, -0.43, -0.31};
    double X[] = {-2.36, -3.23, -1.2, 0.46};
    int iterations[] = {3, 6, 8, 10, 11, 15, 16, 19, 23, 24, 26, 29};

    jacobi(A, B, X, iterations, iterations[sizeof(iterations) / sizeof(int) - 1]);
}