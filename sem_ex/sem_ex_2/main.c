#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FALSE 0
#define BOOLEAN int

void biggest_num(int, int);

int main()
{
    //#1
    BOOLEAN is_init = FALSE;
    int a, b, a_max, b_max;
    while(1)
    {
        printf("Enter a: ");
        scanf("%d", &a);
        if(!a)
        {
            break;
        }
        printf("Enter b: ");
        scanf("%d", &b);
        if(!b)
        {
            break;
        }
        if(!is_init)
        {
            a_max = a;
            b_max = b;
            is_init = !is_init;
        }
        else
        {
            if(a_max < a)
            {
                a_max = a;
            }
            if(b_max < b)
            {
                b_max = b;
            }
        }
    }
    biggest_num(a_max,b_max);

    //#2
    int h,m,min;
    printf("Hour: ");
    scanf("%d", &h);
    printf("Min: ");
    scanf("%d", &m);
    min = m + 15;

    if(min > 60)
    {
        h++;
        if(h == 24)
        {
            h = 0;
        }
        min -= 60;
    }
    if(min < 10)
    {
        printf("%d:0%d", h, min);
    }
    else
    {
        printf("%d:%d", h, min);
    }

    //#3
    int a,b,c;
    printf("A: ");
    scanf("%d", &a);
    printf("B: ");
    scanf("%d", &b);
    printf("C: ");
    scanf("%d", &c);

    if(a == b && b == c)
    {
        printf("The numbers are equal");
    }
    else
    {
        printf("The numbers are not equal");
    }

    //#4
    int number_p;
    double bonus_p = 0, all_points;
    printf("Points: ");
    scanf("%d", &number_p);

    if(number_p <= 100)
    {
        bonus_p += 5;
    }
    else if(number_p > 100 && number_p <= 1000)
    {
        bonus_p = number_p * 0.2;
    }
    else
    {
        bonus_p = number_p * 0.1;
    }

    if(number_p % 2 == 0)
    {
        bonus_p += 1;
    }
    else if(number_p % 10 == 5)
    {
        bonus_p += 2;
    }
    all_points = number_p + bonus_p;
    printf("Bonus points: %0.1lf\n", bonus_p);
    printf("All points: %0.1lf\n", all_points);

    //#5
    int s1,s2,s3, min = 0, sum;
    printf("s1: ");
    scanf("%d", &s1);
    printf("s2: ");
    scanf("%d", &s2);
    printf("s3: ");
    scanf("%d", &s3);
    sum = s1 + s2 + s3;
    while(sum > 60)
    {
        min += 1;
        sum -= 60;
    }

    if(sum < 10)
    {
        printf("%d:0%d", min, sum);
    }
    else
    {
        printf("%d:%d", min, sum);
    }

    //#6
    int x,y,x1,y1,x2,y2;
    printf("X: ");
    scanf("%d", &x);
    printf("Y: ");
    scanf("%d", &y);
    printf("X1: ");
    scanf("%d", &x1);
    printf("Y1: ");
    scanf("%d", &y1);
    printf("X2: ");
    scanf("%d", &x2);
    while(x1 >= x2)
    {
        printf("X2 must be bigger than X1. Enter X2 again: ");
        scanf("%d", &x2);
    }
    printf("Y2: ");
    scanf("%d", &y2);
    while(y1 >= y2)
    {
        printf("Y2 must be bigger than Y1. Enter Y2 again: ");
        scanf("%d", &x2);
    }

    if((x >= x1 && x <= x2) && (y >= y1 && y <= y2))
    {
        printf("Inside");
    }
    else
    {
        printf("Outside");
    }

    //#10
    int n;
    double p1,p2,p3,p4,p5;
    p1=p2=p3=p4=p5=0;
    printf("Enter N: ");
    scanf("%d", &n);
    int array[n];

    srand(time(NULL));

    for(int i = 0; i < n; i++)
    {
        array[i] = rand() % 1000;
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    for(int i = 0; i < n; i++)
    {
        if(array[i] < 200)
        {
            p1 += 1;
        }
        else if(array[i] > 199 && array[i] < 400)
        {
            p2 += 1;
        }
        else if(array[i] > 399 && array[i] < 600)
        {
            p3 += 1;
        }
        else if(array[i] > 599 && array[i] < 800)
        {
            p4 += 1;
        }
        else
        {
            p5 += 1;
        }
    }
    printf("\n");
    p1 = p1/n * 100;
    p2 = p2/n * 100;
    p3 = p3/n * 100;
    p4 = p4/n * 100;
    p5 = p5/n * 100;

    printf("The percentage of p1: %0.2lf\n", p1);
    printf("The percentage of p2: %0.2lf\n", p2);
    printf("The percentage of p3: %0.2lf\n", p3);
    printf("The percentage of p4: %0.2lf\n", p4);
    printf("The percentage of p5: %0.2lf\n", p5);

    return 0;
}

void biggest_num(int a, int b)
{
    if(a > b)
    {
        printf("The biggest number: %d", a);
    }
    else
    {
        printf("The biggest number: %d", b);
    }
}
