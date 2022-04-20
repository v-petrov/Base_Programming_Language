#include "sem_ex_5.h"


void ex_1()
{
    party table, chair, cups, dishes;
    table.quantity = 8;
    table.price = 42;
    chair.price = 13.99;
    cups.quantity = 6;
    cups.price = 5.98;
    dishes.quantity = 6;
    dishes.price = 21.02;

    int guests, cnt_t = 0, cnt_ch = 0, cnt_d = 0, cnt_c = 0, people;
    float sum = 0;
    char *word;
    word = (char *)malloc(10*sizeof(char));
    printf("Enter the number of guests: ");
    scanf("%d", &guests);
    while(1)
    {
        scanf("%s", word);
        fflush(stdin);
        if(!strcmp(word, "PARTY!"))
        {
            break;
        }
        else if(!strcmp(word, "Table"))
        {
            sum += table.price;
            cnt_t++;
        }
        else if(!strcmp(word, "Chair"))
        {
            sum += chair.price;
            cnt_ch++;
        }
        else if(!strcmp(word, "Cups"))
        {
            sum += cups.price;
            cnt_c++;
        }
        else if(!strcmp(word, "Dishes"))
        {
            sum += dishes.price;
            cnt_d++;
        }
    }
    printf("\nThe sum is: %.2f\n", sum);
    int cnt_mt = 0, cnt_mc = 0, cnt_md = 0;
    if(guests > table.quantity*cnt_t)
    {
        if((guests - table.quantity*cnt_t ) < table.quantity)
        {
            printf("1 Table\n");
        }
        else
        {
            people = guests - table.quantity*cnt_t;
            while(people > 0)
            {
                people -= table.quantity;
                cnt_mt++;
            }
            printf("%d Tables\n", cnt_mt);
        }
    }
    if(guests > cnt_ch)
    {
        printf("%d Chair/s\n", guests - cnt_ch);
    }
    if(guests > cups.quantity*cnt_c)
    {
        if((guests - cups.quantity*cnt_c ) < cups.quantity)
        {
            printf("1 Cups\n");
        }
        else
        {
            people = guests - cups.quantity*cnt_c;
            while(people > 0)
            {
                people -= cups.quantity;
                cnt_mc++;
            }
            printf("%d Cups\n", cnt_mc);
        }
    }
    if(guests > dishes.quantity*cnt_d)
    {
        if((guests - dishes.quantity*cnt_d) < dishes.quantity)
        {
            printf("1 Dishes\n");
        }
        else
        {
            people = guests - dishes.quantity*cnt_d;
            while(people > 0)
            {
                people -= dishes.quantity;
                cnt_md++;
            }
            printf("%d Dishes\n", cnt_md);
        }
    }
}

void ex_2()
{
    product products[SIZE];
    order orders[SIZE];

    for(int i = 0; i <  SIZE; i++)
    {
        printf("\nProduct\n");
        printf("Name of the product: ");
        scanf("%s", products[i].name);
        printf("Price of the product: ");
        scanf("%f", &products[i].price);
        printf("Unique number of the product: ");
        scanf("%d", &products[i].unique_num);
    }

    for(int j = 0; j < SIZE; j++)
    {
        printf("\nOrders\n");
        printf("The address: ");
        scanf("%s", orders[j].address);
        printf("Number of the product: ");
        scanf("%d", &orders[j].num_of_pr);
    }

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(products[i].unique_num == orders[j].num_of_pr)
            {
                printf("\nOrder #%d will be delivered at:\n", j + 1);
                printf("Client's address: %s, ordered: %s\n", orders[j].address, products[i].name);
            }
        }
    }
}

int main()
{
    //ex_1();
    //ex_2();
    return 0;
}
