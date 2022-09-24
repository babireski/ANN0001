#include <stdio.h>
#define rows 4
#define columns 5

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
        {-10.73, 2.48, -4.8, 2.39, 4.86},
        {3.04, 7.69, 1.31, -2.28, 4.68},
        {3.71, -3.75,  9.72, -1.21, -0.44},
        {2.37, 3.88, 0.65, 7.96, 3.74}
    };

    double X[rows] = {0.18, 1.99, 0.9, -2.46};
    int iterations[] = {1 , 3, 4, 5, 6, 7, 11, 12, 16, 17, 23, 25};

    seidel(E, X, iterations, iterations[sizeof(iterations) / sizeof(int) - 1]);
}