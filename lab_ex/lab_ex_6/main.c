#include <stdio.h>
#include <stdlib.h>

int main()
{
    //#1
    int n, *p, sum = 0;
    printf("N: ");
    scanf("%d", &n);

    p = (int *)malloc(n*sizeof(int));
    if(p == NULL)
    {
        printf("Error!");
        exit(1);
    }

    for(int i = 0; i < n; i++)
    {
        printf("#%d: ", i + 1);
        scanf("%d", p+i);
        sum += *(p+i);
    }

    printf("The sum is: %d\n\n", sum);

    //#2
    int n1;
    printf("N1: ");
    scanf("%d", &n1);
    p = (int*)realloc(p,n1*sizeof(int));
    if(p == NULL)
    {
        printf("Error!");
        exit(1);
    }
    if(n1 > n)
    {
        for(int i = n; i < n1; i++)
        {
            printf("#%d: ", i + 1);
            scanf("%d", p+i);
        }
    }
    printf("\n");
    for(int i = 0; i < n1; i++)
    {
        printf("#%d: %d\n", i + 1, *(p + i));
    }
    free(p);
    return 0;
}
