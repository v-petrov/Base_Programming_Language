#include "array_h.h"

int main()
{
    int array[SIZE], cnt, sort[SIZE];

    random_array(array, SIZE);
    display_array(array, SIZE);
    printf("Elements with same last 2 digits:\n");
    cnt = fill_array(array, sort, SIZE);
    if(cnt)
    {
        display_array(sort, cnt);
    }
    else
    {
        printf("No such data!");
    }
    printf("Elements with same first and last digit:\n");
    cnt = fill_array_f_l(array, sort, SIZE);
    if(cnt)
    {
        display_array(sort, cnt);
    }
    else
    {
        printf("No such data!");
    }
    return 0;
}
