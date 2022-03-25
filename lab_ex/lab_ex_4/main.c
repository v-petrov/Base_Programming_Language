#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum(int *, int);
float average_positive(int *, int);

int main()
{
    //int array[5] = {}; //only zeroes;
    //    int A[10];
    //    int* p;
    //    p = A;

    //#1
//    int A[7], max;
//
//    srand(time(NULL));
//
//    for(int i = 0; i < 7; i++)
//    {
//        A[i] = rand() % 100 - 50;
//    }
//
//    for(int i = 0; i < 7; i++)
//    {
//        printf("%d\n", *(A+i));
//    }
//
//    max = A[0];
//
//    for(int i = 0; i < 7; i++)
//    {
//        if(max < *(A+i))
//        {
//            max = *(A+i);
//        }
//    }
//
//    printf("Max: %d", max);

    //#2
//    int nums[5] = {1,2,3,4,5}, sum;
//    sum = sum(nums, 5);
//    printf("Sum: %d", sum);

    //#3
    int nums[7];
    float average;

    srand(time(NULL));

    for(int i = 0; i < 7; i++)
    {
        nums[i] = rand() % 15 - 5;
    }

    for(int i = 0; i < 7; i++)
    {
        printf("%d\n", nums[i]);
    }

    average = average_positive(nums, 7);
    printf("Average of positive numbers: %.2f", average);

    return 0;
}

int sum(int array[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += *(array + i);
    }

    return sum;
}

float average_positive(int array[], int size)
{
    float sum = 0, average;
    int cnt = 0;
    for(int i = 0; i < size; i++)
    {
        if(array[i] > 0)
        {
            sum += array[i];
            cnt++;
        }
    }
    average = sum / cnt;
    return average;
}
