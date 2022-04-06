#ifndef SEM_EX_4_H_INCLUDED
#define SEM_EX_4_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void filling_array(int **nums, unsigned row, unsigned col)
{
    srand(time(NULL));

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            nums[i][j] = rand() % 50;
        }
    }
}
void displaying_array(int **nums, unsigned row, unsigned col)
{
    for(int i = 0; i< row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d ", nums[i][j]);
        }
        printf("\n");
    }
}
void check_rows_for_ascending(int **nums, unsigned n, unsigned m)
{
    for(int i = 0; i< n; i++)
    {
        int row_cnt = 0;
        for(int j = 0; j < m - 1; j++)
        {
            if(nums[i][j] < nums[i][j+1])
            {
                row_cnt++;
            }
        }
        if(row_cnt == m - 1)
        {
            printf("\nRow #%d has numbers in ascending order\n", i + 1);
        }
        else
        {
            printf("\nRow #%d not in ascending order\n", i + 1);
        }
    }
}
void check_cols_for_descending(int **nums, unsigned m, unsigned n)
{
    for(int j = 0; j < m; j++)
    {
        int col_cnt = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i][j] > nums[i + 1][j])
            {
                col_cnt++;
            }
        }
        if(col_cnt == n - 1)
        {
            printf("\nCol #%d has numbers in descending order\n", j + 1);
        }
        else
        {
            printf("\nCol #%d not in descending order\n", j + 1);
        }
    }
}
void free_memory(int **nums, unsigned n)
{
    for(int i = 0; i < n; i++)
    {
        free(nums[i]);
        nums[i] = NULL;
    }
    free(nums);
}
void swapping_rows(int **nums, unsigned n, unsigned m)
{
    int r_max = 0,r_min = 0,max_num = nums[0][0],min_num = nums[0][0];
    for(int i = 0;i < n; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            if(max_num < nums[i][j])
            {
                max_num = nums[i][j];
                r_max = i;
            }
            if(min_num > nums[i][j])
            {
                min_num = nums[i][j];
                r_min = i;
            }
        }
    }

    printf("\nThe max number is: %d, its row is: %d\n", max_num, r_max + 1);
    printf("\nThe min number is: %d, its row is: %d\n\n", min_num, r_min + 1);

    if(r_max != r_min)
    {
        int temp;
        for(int j = 0; j < m; j++)
        {
            temp = nums[r_max][j];
            nums[r_max][j] = nums[r_min][j];
            nums[r_min][j] = temp;
        }
    }
    else
    {
        printf("No swapping, they are on the same row!");
    }

}
void add(int *nums, int *n,int *m)
{
    nums = (int*)realloc(nums, (*n+1)*sizeof(int));
    nums[*n] = *m;
    (*n)++;
}
void delete_n(int *nums, int *n,int *x)
{
    int cnt = 0, j = 0, k, temp, cnt_1;
    for(int i = 0; i < *n; i++)
    {
        if(nums[i] == *x)
        {
            cnt++;
        }
    }
    if(!cnt)
    {
        return;
    }
    else
    {
        cnt_1 = cnt;
        while(cnt != 0)
        {
            if(nums[j] == *x)
            {
                k = j;
                for(int i = k; i < *n - 1; i++)
                {
                    temp = nums[i];
                    nums[i] = nums[i + 1];
                    nums[i + 1] = temp;
                }
                cnt--;
                j = 0;
            }
            j++;
        }
    }
    nums = (int*)realloc(nums, (*n - cnt_1)*sizeof(int));
    for(int i = 0; i < *n - cnt_1; i++)
    {
        printf("%d ", *(nums + i));
    }
}
#endif // SEM_EX_4_H_INCLUDED
