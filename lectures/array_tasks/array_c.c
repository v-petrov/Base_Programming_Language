#include "array_h.h"

void random_array(int data[], unsigned size)
{
    srand(time(NULL));

    for(int i = 0; i < size; i++)
    {
        data[i] = rand();
    }
}

void display_array(int data[], unsigned size)
{
    for(int i = 0 ; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

unsigned fill_array(int data[], int sort[], unsigned size)
{
    unsigned j = 0;
    for(int i = 0; i < size; i++)
    {
        if(data[i] % 10 == data[i]/10 % 10)
        {
            sort[j++] = data[i];
        }
    }
    return j;
}

int first_digit(int n)
{
    int n1;
    n1 = n;
    while(n1 / 10 != 0)
    {
        n1 /= 10;
    }
    return n1;
}

int last_digit(int n)
{
    return n % 10;
}

unsigned fill_array_f_l(int data[], int sort[], unsigned size)
{
    unsigned j = 0;
    for(int i = 0; i < size; i++)
    {
        if(first_digit(data[i]) == last_digit(data[i]))
        {
            sort[j++] = data[i];
        }
    }
    return j;
}
