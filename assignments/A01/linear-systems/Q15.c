#include <stdio.h>
#include <math.h>
#define PI 	3.14159265358979323846
#define A 53 * PI / 180
#define B 52 * PI / 180
#define F 2273

int main(void) {
    double F1 = (-F * cos(B)) / (sin(A + B));
    double F2 = (F * cos(A + B) + F * cos(A - B)) / (2 * sin(A + B));
    double F3 = (-F * cos(A)) / (sin(A + B));
    double H2 = 0;
    double V2 = (F * sin(A + B) + F * sin(A - B)) / (2 * sin(A + B));
    double V3 = (F * sin(A + B) -F * sin(A - B)) / (2 * sin(A + B));

    printf("%.16lf,%.16lf,%.16lf,%.16lf,%.16lf,%.16lf\n", F1, F2, F3, H2, V2, V3);

    return 0;
}