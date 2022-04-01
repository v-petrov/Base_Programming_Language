#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CHECKING_ERROR          \
    if(p == NULL)               \
    {                           \
        printf("Error!");       \
        exit(1);                \
    }                           \

int main()
{
    //#1
    int n, *p, sum = 0;
    printf("N: ");
    scanf("%d", &n);

    p = (int *)malloc(n*sizeof(int));
    CHECKING_ERROR;

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
    CHECKING_ERROR;

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

    //#3
    int n, *p, *np, cnt = 0, j = 0;
    printf("N: ");
    scanf("%d", &n);

    srand(time(NULL));

    p = (int*)calloc(n,sizeof(int));
    CHECKING_ERROR;

    for(int i = 0; i < n; i++)
    {
        p[i] = rand() % 100 - 20;
    }
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", *(p+i));
    }
    for(int i = 0; i < n; i++)
    {
        if(*(p + i) > 0 && *(p + i) % 5 == 0)
        {
            cnt++;
        }
    }
    printf("\n\n");
    np = (int*)calloc(cnt,sizeof(int));
    if(np == NULL)
    {
        printf("Error!");
        exit(1);
    }
    for(int i = 0; i < n; i++)
    {
        if(*(p + i) > 0 && *(p + i) % 5 == 0)
        {
            np[j++] = p[i];
        }
    }
    for(int i = 0; i < cnt; i++)
    {
        printf("%d ", *(np+i));
    }
    free(p);
    free(np);

    //#4
    int row, col, *sum_of_cols, sum;
    printf("Rows: ");
    scanf("%d", &row);
    printf("Cows: ");
    scanf("%d", &col);

    srand(time(NULL));

    int* array[row];
    for(int i = 0; i < row; i++)
    {
        array[i] = (int *)malloc(col * sizeof(int));
        if(array[i] == NULL)
        {
            printf("Error!");
            exit(1);
        }
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j< col; j++)
        {
            array[i][j] = rand() % 50 - 20;
        }
    }
    printf("\n");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j< col; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    sum_of_cols = (int*)calloc(col, sizeof(int));
    if(sum_of_cols == NULL)
    {
        printf("Error!");
        exit(1);
    }

    for(int j = 0; j < col; j++)
    {
        sum = 0;
        for(int i = 0; i < row; i++)
        {
            sum += array[i][j];
        }
        sum_of_cols[j] = sum;
    }

    int max_sum = sum_of_cols[0];
    for(int i = 1; i < col; i++)
    {
        if(max_sum < sum_of_cols[i])
        {
            max_sum = sum_of_cols[i];
        }
    }

    printf("\nMax sum of the cols is: %d\n", max_sum);

    for(int i = 0; i < row; i++)
    {
        free(array[i]);
    }
    free(sum_of_cols);

    return 0;
}
