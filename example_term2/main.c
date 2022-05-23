#include "example_term2.h"

int main()
{
    int x;
    x = products_cnt();
    Products *products = (Products *)calloc(x, sizeof(Products));
    if(products == NULL)
    {
        perror(NULL);
        exit(1);
    }

    products_info(products);

    FILE *fp_b = fopen("binary", "wb");
    if(fp_b == NULL)
    {
        perror("Error file_b writing");
        exit(1);
    }

//    for(int i = 0; i < x; i++)
//    {
//        if(fwrite(&products[i], sizeof(products[i]), 1, fp_b) != 1)
//        {
//            perror(NULL);
//            fclose(fp_b);
//            exit(1);
//        }
//    }
    if(fwrite(products, sizeof(products[0]), x, fp_b) != x)
    {
        perror(NULL);
        fclose(fp_b);
        exit(1);
    }

    char c;
    int pr;
    printf("Do you want to add a new product(Y/N): ");
    scanf("%c", &c);
    if(c == 'Y' || c == 'y')
    {
        printf("How many you would like to add: ");
        scanf("%d", &pr);
        while(pr != 0)
        {
            products = add_new_item(products, &x, fp_b);
            pr--;
        }
    }
    fclose(fp_b);

    Products *date_exp;
    char *date = (char *)malloc(11*sizeof(char));
    if(date == NULL)
    {
        perror(NULL);
        exit(1);
    }
    int cnt_exp_date;
    printf("Enter an expiration date: ");
    scanf("%s", date);

    date_exp = expiration_date(products, date, &x);
    cnt_exp_date = exp_date_cnt(products, date, &x);
    if(!cnt_exp_date)
    {
        printf("There are no products with that expiration date!\n");
    }
    else
    {
        for(int i = 0; i < cnt_exp_date; i++)
        {
            printf("Name: %s\n", date_exp[i].name);
            printf("Name: %lu\n", date_exp[i].ID);
            printf("Exp Date: %s\n", date_exp[i].exp_date);
            printf("Price: %.2f\n\n", date_exp[i].price);
        }
    }

    fp_b = fopen("binary", "rb");
    if(fp_b == NULL)
    {
        perror(NULL);
        exit(1);
    }

    FILE *fp_t = fopen("outText.txt", "w");
    if(fp_t == NULL)
    {
        perror(NULL);
        exit(1);
    }

    Products *obuff = (Products *)calloc(1,sizeof(Products));
    if(obuff == NULL)
    {
        perror(NULL);
        exit(1);
    }

    for(int i = 0; i < x; i++)
    {
        if(fread(obuff, sizeof(obuff), 4, fp_b) != 4)
        {
            perror("ERROR WITH READING fp_b1");
            fclose(fp_b);
            exit(1);
        }
        fprintf(fp_t, "Meat: %s\nID: %lu\nExpire Date: %s\nPrice: %.2f\n\n", obuff->name, obuff->ID, obuff->exp_date, obuff->price);
    }

    fclose(fp_t);
    fclose(fp_b);
    for(int i = 0; i < x; i++)
    {
        free(products[i].name);
        free(products[i].exp_date);

    }
    free(obuff);
    free(products);
    free(date_exp);

    return 0;
}
