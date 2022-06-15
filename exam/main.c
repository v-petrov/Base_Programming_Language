#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NL printf("\n");

typedef struct Members
{
    char f_l_name[56];
    char unique_num[7];
    double price;
    int code;
}Members;

void fill_info(Members *, int);
void add_member(Members **, int *, FILE *);
void avr_price(Members *, int);
void bin_info(Members *, int, char *);

int main()
{
    int n;
    printf("Enter the number of members: ");
    scanf("%d", &n);
    Members *members = (Members*)malloc(n*sizeof(Members));
    if(members == NULL)
    {
        perror(NULL);
        exit(1);
    }

    fill_info(members, n);

    FILE *fp_t = fopen("membersText.txt", "w");
    if(fp_t == NULL)
    {
        perror(NULL);
        exit(1);
    }

    for(int i = 0; i < n; i++)
    {
        fprintf(fp_t, "%d;%s;%s;%.2f;%d\n", strlen(members[i].f_l_name), members[i].f_l_name, members[i].unique_num, members[i].price, members[i].code);
    }

    add_member(&members, &n, fp_t);

    avr_price(members, n);

    char *unique = (char*)malloc(7*sizeof(char));
    if(unique == NULL)
    {
        perror(NULL);
        exit(1);
    }
    printf("Enter a unique number like (AA1234): ");
    scanf("%s", unique);
    bin_info(members, n, unique);

    free(members);
    free(unique);
    fclose(fp_t);

    return 0;
}

void fill_info(Members *members, int size)
{
    for(int i = 0; i < size; i++)
    {
        fflush(stdin);
        printf("Names: ");
        scanf("%[^\n]s", members[i].f_l_name);
        printf("Unique number: ");
        scanf("%s", members[i].unique_num);
        printf("Price: ");
        scanf("%lf", &members[i].price);
        printf("Code: ");
        scanf("%d", &members[i].code);
        NL;
    }
}
void add_member(Members **members, int *size, FILE *fp_t)
{
    (*size)++;
    *members = (Members *)realloc(*members,sizeof(Members)*(*size));
    if(*members == NULL)
    {
        perror(NULL);
        exit(1);
    }

    fflush(stdin);
    printf("Names: ");
    scanf("%[^\n]s", (*members)[*size - 1].f_l_name);
    printf("Unique number: ");
    scanf("%s", (*members)[*size - 1].unique_num);
    printf("Price: ");
    scanf("%lf", &(*members)[*size - 1].price);
    printf("Code: ");
    scanf("%d", &(*members)[*size - 1].code);
    NL;

    fprintf(fp_t, "%d;%s;%s;%.2f;%d\n", strlen((*members)[*size - 1].f_l_name), (*members)[*size - 1].f_l_name, (*members)[*size - 1].unique_num, (*members)[*size - 1].price, (*members)[*size - 1].code);
}
void avr_price(Members *members, int size)
{
    double avr = 0;
    for(int i = 0; i < size; i++)
    {
        avr += members[i].price;
    }
    avr /= size;

    for(int i = 0; i < size; i++)
    {
        if(members[i].price < avr)
        {
            printf("%s - %s - %.2f\n", members[i].f_l_name, members[i].unique_num, members[i].price);
        }
    }
    NL;
}
void bin_info(Members *members, int size, char *unique)
{
    int ff = 0;
    FILE *fp_b = fopen("members.bin", "rb");
    if(fp_b == NULL)
    {
        perror(NULL);
        exit(1);
    }

    Members *unq_member = (Members*)malloc(sizeof(Members));

    for(int i = 0; i < size; i++)
    {
        fseek(fp_b, strlen(members[i].f_l_name), SEEK_CUR);
        if(fread(unq_member, sizeof(Members), 1, fp_b))
        {
            perror(NULL);
            exit(1);
        }

        if(!strcmp(members[i].unique_num, unique))
        {
            ff = 1;
            printf("Bin Names: %s\n", unq_member->f_l_name);
            printf("Bin ID: %s\n", unq_member->unique_num);
            printf("Bin M_Price: %.2f\n", unq_member->price);
            printf("Bin Locker: %d\n", unq_member->code);
            NL;
        }
        break;
    }

    if(!ff)
    {
        printf("No such unique number!\n");
    }

    free(unq_member);
    fclose(fp_b);
}
