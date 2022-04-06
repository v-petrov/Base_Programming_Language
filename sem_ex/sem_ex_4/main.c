#include "sem_ex_4.h"

int main()
{
    //#1
    int n,m;
    printf("Array[N][M]\n");
    printf("N: ");
    scanf("%d", &n);
    printf("M: ");
    scanf("%d", &m);

    int **nums;

    nums = (int**)malloc(n*sizeof(int*));
    if(nums == NULL)
    {
        printf("Error in memory!");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < n; i++)
    {
        nums[i] = (int*)calloc(m, sizeof(int));
        if(nums[i] == NULL)
        {
            printf("Error in memory!");
            exit(EXIT_FAILURE);
        }
    }

    filling_array(nums, n, m);

    displaying_array(nums, n, m);

    check_rows_for_ascending(nums, n, m);

    check_cols_for_descending(nums, m, n);

    //#2
    swapping_rows(nums, n, m);

    displaying_array(nums, n, m);

    free_memory(nums, n);

    //#5
    int *nums,n,x,m;
    printf("N: ");
    scanf("%d", &n);
    nums = (int*)malloc(n*sizeof(int));

    srand(time(NULL));

    for(int i = 0; i < n; i++)
    {
        *(nums + i) = rand() % 50 - 10;
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d ", *(nums + i));
    }

    printf("\nM: ");
    scanf("%d", &m);

    add(nums, &n, &m);

    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", *(nums + i));
    }

    printf("\n\n");
    printf("X: ");
    scanf("%d", &x);

    delete_n(nums, &n, &x);

    free(nums);

    return 0;
}
