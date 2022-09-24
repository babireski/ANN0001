#include <stdbool.h>
#include <stdio.h>
#define rows 3
#define columns 3

// void jacobi(double E[rows][columns], double X[rows], int iterations[], int n)
// {
//     double N[rows];
//     int counter = 0;

//     for(int k = 0; k < n; k++)
//     {
//         for(int i = 0; i < rows; i++)
//         {
//             double bi = E[i][columns - 1];
//             double soma = 0;

//             for(int j = 0; j < columns - 1; j++)
//             {
//                 if (i != j)
//                 {
//                     soma += E[i][j] * X[j];
//                 }
//             }

//             double xi = (bi - soma) / E[i][i];
//             N[i] = xi;
//             printf("x_%d^(%d) = %.16f\t", i + 1, k + 1, xi);
//         }

//         printf("\n");

//         for (int i = 0; i < rows; i++)
//         {
//             X[i] = N[i];
//         }

//         if(k + 1 == iterations[counter])
//         {
//             if(counter) printf(",\n");

//             for(int i = 0; i < rows; i++)
//             {
//                 if(i) printf(", ");
//                 printf("%.16f", X[i]);
//             }

//             counter++;
//         }
//     }
// }

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
        { 4,  1, -1},
        {-1,  3,  1},
        { 1, -1,  5}    
    };

    double B[] = {5, 6, 4};
    double X[] = {0, 0, 0};
    int iterations[] = {1, 2, 3, 4, 5};

    jacobi(A, B, X, iterations, sizeof(iterations) / sizeof(int));
}