#include "sin_h.h"

int main()
{
    double x;
    double xrad;
    printf("x = ");
    scanf("%lf", &x);
    xrad = x/180*M_PI;

    printf("sin_x(%g) = %lf\n", x, sin_x(xrad));
    printf("sin_AE(%g) = %lf\n", x, sin_x_AE(xrad));
    printf("sin_math(%g) = %lf\n", x, sin(xrad));
    printf("cos_x(%g) = %lf\n", x, cos_x(xrad));
    printf("cos_math(%g) = %lf\n", x, cos(xrad));
    return 0;
}
