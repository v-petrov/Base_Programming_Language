#include "dynamic_arrays.h"

int main()
{
    float *data;
    data = (float*)malloc(5*sizeof(float));

    if(data == NULL)
    {
        perror(NULL);
        exit(EXIT_FAILURE);
    }

    filling_array(data, 5);
    displaying_array(data, 5);
    free(data);

    printf("\n2D ARRAY!!!\n\n");

    float **data_2D;
    data_2D = (float**)malloc(5*sizeof(float*));

    if(data_2D == NULL)
    {
        perror(NULL);
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < 5; i++)
    {
        data_2D[i] = (float*)calloc(i+1, sizeof(float));
        if(data_2D[i] == NULL)
        {
            free_data(data_2D, i);
            printf("Error!");
            exit(1);
        }
    }

    filling_array_2D(data_2D, 5);
    displaying_array_2D(data_2D, 5);
    free_data(data_2D, 5);
    return 0;
}
