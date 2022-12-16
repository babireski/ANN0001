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
        {-5.51, 2.65, 1.38, -3.79},
        {-3.32, -5.03, -0.23, -1.83},
        {-3.25, 2.7, 7.44, -2.96}    
    };

    double X[rows] = {-4.72, -2.31, 1.88};
    int iterations[] = {7 , 8, 11, 12, 15, 17, 18, 19};

    seidel(E, X, iterations, iterations[sizeof(iterations) / sizeof(int) - 1]);
}