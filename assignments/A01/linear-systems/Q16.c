#include <stdio.h>
#include <math.h>
#define At 3760 /* Areia precisa */
#define Ft 4194 /* Cascalho fino preciso */
#define Gt 3657 /* Cascalho grosso preciso */
#define A1 0.55 /* Areia da primeira mina */
#define A2 0.29 /* Areia da segunda mina */
#define A3 0.16 /* Areia da terceira mina */
#define F1 0.26 /* Cascalho fino da primeira mina */
#define F2 0.45 /* Cascalho fino da segunda mina */
#define F3 0.36 /* Cascalho fino da terceira mina */
#define G1 0.19 /* Cascalho grosso da primeira mina */
#define G2 0.26 /* Cascalho grosso da segunda mina */
#define G3 0.48 /* Cascalho grosso da terceira mina */
#define m 3
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
    double E[m][n] =
    {
        {A1, A2, A3, At},
        {F1, F2, F3, Ft},
        {G1, G2, G3, Gt}
    };

    gauss(E);
    print(E);

    return 0;
}