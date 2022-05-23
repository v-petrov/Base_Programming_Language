#ifndef EXAMPLE_TERM2_H_INCLUDED
#define EXAMPLE_TERM2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Products
{
    char *name;
    long unsigned ID;
    char *exp_date;
    float price;
}Products;

int products_cnt()
{
    FILE *fp_t = fopen("products.txt", "r");
    if(fp_t == NULL)
    {
        perror("Error file_t opening");
        exit(1);
    }
    char *buff = (char *)malloc(sizeof(char)*BUFSIZ);
    if(buff == NULL)
    {
        perror(NULL);
        exit(1);
    }

    int cnt = 0;
    while(fgets(buff, BUFSIZ, fp_t) != NULL)
    {
        cnt++;
    }
    free(buff);
    fclose(fp_t);
    return cnt;
}

void products_info(Products *products)
{
    FILE *fp_t = fopen("products.txt", "r");
    if(fp_t == NULL)
    {
        perror("Error file_t opening");
        exit(1);
    }
    int i = 0;
    while(!feof(fp_t))
    {
        products[i].name = (char *)calloc(30, sizeof(char));
        if(products[i].name == NULL)
        {
            perror(NULL);
            exit(1);
        }
        products[i].exp_date = (char *)calloc(11, sizeof(char));
        if(products[i].exp_date == NULL)
        {
            perror(NULL);
            exit(1);
        }
        fscanf(fp_t, "%s %lu %s %f", products[i].name, &products[i].ID, products[i].exp_date, &products[i].price);
        i++;
    }
    fclose(fp_t);
}

Products *add_new_item(Products *products, int *x, FILE *fp_b)
{
    (*x)++;
    products = (Products *)realloc(products, sizeof(Products)*(*x));
    if(products == NULL)
    {
        perror(NULL);
        exit(1);
    }

    (products + (*x - 1))->name = (char *)calloc(30, sizeof(char));
    if((products + (*x - 1))->name == NULL)
    {
        perror(NULL);
        exit(1);
    }

    (products + (*x - 1))->exp_date = (char *)calloc(11, sizeof(char));
    if((products + (*x - 1))->exp_date == NULL)
    {
        perror(NULL);
        exit(1);
    }

    printf("Name: ");
    scanf("%s", (products + (*x - 1))->name);
    printf("ID: ");
    scanf("%lu", &(products + (*x - 1))->ID);
    printf("Expire Date: ");
    scanf("%s", (products + (*x - 1))->exp_date);
    printf("Price: ");
    scanf("%f", &(products + (*x - 1))->price);

    if(fwrite((&products[*x - 1]), sizeof(products[*x - 1]), 1, fp_b) != 1)
    {
        perror("PROBLEM WITH WRITING fp_b");
        exit(1);
    }
    else
    {
        printf("Successfully written in the file!\n");
    }
    return products;
}

Products *expiration_date(Products *products, char *date, int *x)
{
    int cnt = 0;
    Products *date_exp = (Products *)calloc(cnt, sizeof(Products));
    if(date_exp == NULL)
    {
        perror(NULL);
        exit(1);
    }
    for(int i = 0; i < (*x); i++)
    {
        if(!strcmp(products[i].exp_date, date))
        {
            cnt++;
            date_exp = (Products *)realloc(date_exp, sizeof(Products)*cnt);
            if(date_exp == NULL)
            {
                perror(NULL);
                exit(1);
            }

            date_exp[cnt - 1] = products[i];
        }
    }
    return date_exp;
}

int exp_date_cnt(Products *products, char *date,int *x)
{
    int cnt = 0;
    for(int i = 0; i < (*x); i++)
    {
        if(!strcmp(products[i].exp_date, date))
        {
            cnt++;
        }
    }
    return cnt;
}

#endif // EXAMPLE_TERM2_H_INCLUDED
