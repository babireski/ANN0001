#include <stdio.h>
#define rows 3
#define columns 4

void seidel(double E[rows][columns], double X[rows], int iterations[], int n)
{
    int counter = 0;

    for(int k = 0; k < n; k++)
    {   
        for(int i = 0; i < rows; i++)
        {
            double sum = 0;

            for(int j = 0; j < columns - 1; j++)
            {
                if (i != j)
                {
                    sum = sum + E[i][j] * X[j];
                }
            }

            X[i] = (E[i][columns - 1] - sum) / E[i][i];
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
    double E[rows][columns] =
    {
        { 4,  1, -1, 5},
        {-1,  3,  1, 6},
        { 1, -1,  5, 4}    
    };

    double X[] = {0, 0, 0};
    int iterations[] = {1, 2, 3, 4, 5};

    seidel(E, X, iterations, iterations[sizeof(iterations) / sizeof(int) - 1]);
}