#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function declaration
double power(int,int);
double power2(int base, int power);

int main()
{
    int a,b;
    printf("a = ");
    scanf("%d",&a);
    printf("b = ");
    scanf("%d",&b);

    printf("Power: %d**%d = %g\n",a,b,power(a,b));
    printf("Power2: %d**%d = %g\n",a,b,power2(a,b));
    printf("Pow: %d**%d = %g\n",a,b,pow(a,b));
    return 0;
}

//function definition
double power(int x,int y)
{
    double retValue = 1;
    int i;

    for(i=1; i<=y;++i) // for(retValue=1;y>=1;--y)
    {
        retValue *= x;
    }
    return retValue;
}

double power2(int base, int power)
{
    return exp(power*log(base));
}
