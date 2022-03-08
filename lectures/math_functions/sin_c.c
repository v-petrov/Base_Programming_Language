#include "sin_h.h"

double sin_x(double x)
{
    double sum = 0;
    double member = x;
    unsigned fact = 3;

    for(int i = 0; i < 10; i++, fact += 2)
    {
        sum += member;
        member *= -x*x/((fact - 1) * fact);
    }
    return sum;
}

double sin_x_AE(double x)
{
    double sum = 0;
    double member = x;
    double member1 = 0;
    unsigned fact = 3;
    int cnt = 0;

    while(fabs(member - member1) >= EPS)
    {
        sum += member;
        member1 = member;
        member *= -x*x/((fact - 1) * fact);
        fact += 2;
        cnt++;
    }
    printf("cnt = %d\n", cnt);
    return sum;
}

double cos_x(double x)
{
    double sum = 0;
    double member = 1;
    unsigned fact = 2;

    for(int i = 0; i < 10; i++, fact += 2)
    {
        sum += member;
        member *= -x*x/((fact - 1) * fact);
    }
    return sum;
}
