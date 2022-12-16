#include <stdio.h>
#include <math.h>

void bissection(double (*f)(double),double a,double b, int n, double tol) {
    double fa = f(a);
    double fb = f(b);

    if(fa*fb >=0) {
        printf("voce nao pode usar esse intervalo");
        return;
    } else {
        for(int i=0;i<n;i++) {
            double m = 0.5*(a+b);
            double fm = f(m);

            if(fabs(fm) ==0) {
                printf("voce encontrou uma raiz r= %.16f",fm);
                return;
            }

            printf("x_%d = %.16f\n",i+1,m);

            if(fabs(fm)<tol) {
                printf("atingiu a tolerancia => x_%d = %.16f\n",i+1,m);
                return;
            }
            if(fa*fm<0) {
                b = m;
            } else {
                a = m;
            }

            

        }
    }
}

double f(double x) {
    return log(pow(x,2))- 0.7;
}

int main() {

    double a =  0.8655;
    double b = 2.2704;
    
    int n = 39;
    
    double tol = 0.0000000000001;

    bissection(f,a,b,n,tol);
    //printf(" \n Valor em vetor: \n");


    return 0;
}