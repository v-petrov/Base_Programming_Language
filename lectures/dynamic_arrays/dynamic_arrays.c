#include "dynamic_arrays.h"

void filling_array(float *data, unsigned len)
{
    srand(time(NULL));

    for(int i = 0; i < len; i++)
    {
        *(data + i) = rand()%50/5.;
    }
}
void displaying_array(float *data, unsigned len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%g ", *(data + i));
    }
    printf("\n");
}
void filling_array_2D(float **data, unsigned len)
{
    srand(time(NULL));

    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j<=i; j++)
        {
            data[i][j] = rand()%50/5.;
        }
    }
}
void displaying_array_2D(float **data, unsigned len)
{
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            printf("%g ", data[i][j]);
        }
        printf("\n");
    }
}
void free_data(float *data[],unsigned len)
{
    for(int j=0;j<len;++j){
        free(data[j]);
        data[j]=NULL;
    }
    free(data);
}
