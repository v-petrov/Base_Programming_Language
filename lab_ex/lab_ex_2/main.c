#include <stdio.h>
#include <stdlib.h>

int main()
{
//    int x;
//    printf("Enter X: ");
//    scanf("%d", &x);
//    if (x > 6)
//    {
//        printf("%d is bigger than 6", x);
//    }
//    else
//    {
//        printf("%d is not bigger than 6", x);
//    }


//    int x,remainder;
//    printf("Enter X: ");
//    scanf("%d", &x);
//    remainder = x % 8;
//
//    if(remainder > 4)
//    {
//        printf("The remainder (%d) is greater than 4", remainder);
//    }
//    else
//    {
//        printf("The remainder (%d) is not greater than 4", remainder);
//    }

//    int x,y,z;
//    printf("Enter X: ");
//    scanf("%d", &x);
//    printf("Enter Y: ");
//    scanf("%d", &y);
//    printf("Enter Z: ");
//    scanf("%d", &z);
//
//    if(x <= y && x <= z)
//    {
//        printf("%d", x);
//    }
//    else if(y <= x && y <= z)
//    {
//        printf("%d", y);
//    }
//    else if(z <= x && z <= y)
//    {
//        printf("%d", z);
//    }

//    int x;
//    printf("Enter X: ");
//    scanf("%d", &x);
//
//    switch(x)
//    {
//        case 1:
//            printf("Monday");
//            break;
//        case 2:
//            printf("Tuesday");
//            break;
//        case 3:
//            printf("Wednesday");
//            break;
//        case 4:
//            printf("Thursday");
//            break;
//        case 5:
//            printf("Friday");
//            break;
//        case 6:
//            printf("Saturday");
//            break;
//        case 7:
//            printf("Sunday");
//            break;
//        default:
//            printf("Not a valid number for a day of the weekend ");
//    }

//    int x,i,j;
//    printf("Enter X: ");
//    scanf("%d", &x);
//
//    for(i = 1; i<=5;++i)
//    {
//        for(j = 1; j <= i; ++j)
//        {
//            printf("%d", x);
//        }
//        x++;
//        printf("\n");
//    }

//    int x,y,i,sum,multy;
//    printf("Enter X: ");
//    scanf("%d", &x);
//    printf("Enter Y: ");
//    scanf("%d", &y);
//
//    if(x < y)
//    {
//        sum = 0;
//        multy =1;
//        for(i = y - 1; i>x; i--)
//        {
//            if(i % 2 == 0)
//            {
//               sum += i;
//            }
//            else
//            {
//               multy *= i;
//            }
//        }
//        printf("The sum is: %d\n", sum);
//        printf("The multy is: %d\n", multy);
//    }
//    else if(x > y)
//    {
//        sum = 0;
//        multy = 1;
//        for(i = y + 1; i<x; i++)
//        {
//            if(i % 2 == 0)
//            {
//               sum += i;
//            }
//            else
//            {
//               multy *= i;
//            }
//        }
//        printf("The sum is: %d\n", sum);
//        printf("The multy is: %d\n", multy);
//    }
//    else
//    {
//        printf("They are equal");
//    }

//    int n,k,x,cnt = 0;
//    printf("Enter N: ");
//    scanf("%d", &n);
//    printf("Enter K: ");
//    scanf("%d", &k);
//
//    while(n > 0)
//    {
//        printf("Enter X: ");
//        scanf("%d", &x);
//
//        if(x < k && (x % 3 != 0))
//        {
//            cnt += 1;
//        }
//        n--;
//    }
//    printf("%d", cnt);

//    int x,sum = 0;
//
//    while(1)
//    {
//        printf("Enter X: ");
//        scanf("%d", &x);
//
//        if(x == 0)
//        {
//            break;
//        }
//        sum+= x;
//    }
//    printf("The sum is: %d", sum);

    double a,b,i,sum = 0.0;
    printf("Enter A: ");
    scanf("%lf", &a);
    printf("Enter B: ");
    scanf("%lf", &b);

    if(a > b)
    {
        double x = a;
        a = b;
        b = x;
    }
    else
    {
        printf("They are equal");
    }

    for(i = a + 0.1; i < b; i+= 0.1)
    {
        printf("The f(%lf) = %lf*%lf-4 = ", i,i,i);
        sum = i*i -4;
        printf("%lf\n", sum);
    }

    return 0;
}
