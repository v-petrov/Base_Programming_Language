#include <stdio.h>
#include <stdlib.h>

int main()
{
    //#1 - getting only the elements on the main diagonal
    int n;
    printf("N: ");
    scanf("%d", &n);

    int array[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("array[%d][%d]: ", i,j);
            scanf("%d", &array[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < n; i++)
    {
        printf("array[%d][%d]: %d\n", i,i,array[i][i]);
    }

    printf("\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    printf("\n#2\n\n");

    //#2 - if there is a negative number in the last row, multiply by 3 the secondary diagonal

    for(int i = 0; i < n; i++)
    {
        if(array[n-1][i] < 0)
        {
            int j = n-1;
            for(int i = 0; i < n; i++)
            {
                array[i][j] *= 3;
                j--;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    printf("\n#3\n\n");

    //#3 - getting the minimum element above the main diagonal
    int min = array[0][1];
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(min > array[i][j])
            {
                min = array[i][j];
            }
        }
    }

    printf("Min: %d", min);

    //#4 - comparing the sums of the rows, and getting the minimum one
    int A[4][5] = {{1,2,3,4,5},{6,7,8,9,10},{2,3,4,5,6},{4,5,6,7,8}};
    int Sum[4];
    int sum = 0;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            sum += A[i][j];
        }
        Sum[i] = sum;
        sum = 0;
    }

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("sum: %d ", Sum[i]);
        printf("\n");
    }

    int min_sum = Sum[0];
    for(int i = 0; i < 4; i++)
    {
        if(min_sum > Sum[i])
        {
            min_sum = Sum[i];
        }
    }

    printf("\nThe min sum is: %d", min_sum);
    return 0;
}
