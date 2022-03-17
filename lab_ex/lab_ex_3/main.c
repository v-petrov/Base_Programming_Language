#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int main()
{
//    void *pv; // summarized pointer
//    int i = 10;
//    double d = 2.34;
//    pv = &i;
//    printf("%d\n", *(int*)pv); // changing the type of the pointer
//    pv = &d;
//    printf("%.2lf\n", *(double*)pv);

    int *pi;
    double *pd;
    char *pc;

    int i;
    double d;
    char c;

    pi = &i;
    pd = &d;
    pc = &c;

    *pi = 3;
    *pd = 3.33;
    *pc = 'b';

    printf("*pi = %d\n", *pi);
    printf("*pd = %.2lf\n", *pd);
    printf("*pc = %c\n\n", *pc);

    printf("pi = %p\n", pi);
    printf("pd = %p\n", pd);
    printf("pc = %p\n\n", pc);

//    (*pi)++;
//    (*pd)++;
//    (*pc)++;
//
//    printf("*pi = %d\n", *pi);
//    printf("*pd = %.2lf\n", *pd);
//    printf("*pc = %c\n\n", *pc);

    pi++;
    pd++;
    pc++;

    printf("pi = %p\n", pi);
    printf("pd = %p\n", pd);
    printf("pc = %p\n\n", pc);

//    int a = 5;
//    int b = 8;
//    swap(&a,&b);
//    printf("a = %d\n", a);
//    printf("b = %d\n", b);
    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
