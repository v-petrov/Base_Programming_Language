#ifndef SEM_EX_5_H_INCLUDED
#define SEM_EX_5_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3

typedef struct Party
{
    float price;
    int quantity;
}party;

typedef struct Product
{
    char name[15];
    float price;
    int unique_num;
}product;

typedef struct Orders
{
    char address[30];
    int num_of_pr;
}order;

#endif // SEM_EX_5_H_INCLUDED
