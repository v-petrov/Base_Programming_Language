#ifndef EXAMPLE_TERM1_H_INCLUDED
#define EXAMPLE_TERM1_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NL printf("\n")

typedef struct CimenaStar
{
    char name[21];
    int age;
    char country[21];
    unsigned long earned_money;
    int num_of_oscars;
}CS;

int stars_cnt(FILE *fp_t)
{
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
    rewind(fp_t);
    free(buff);
    return cnt;
}

void fill_info(FILE *fp_t, CS *cin_stars)
{
    char *buff = (char *)malloc(sizeof(char)*BUFSIZ);
    if(buff == NULL)
    {
        perror(NULL);
        exit(1);
    }
    int i = 0, x;
    unsigned long x_ul;
    char *p;
    char *str = (char *)malloc(sizeof(char)*25);
    if(str == NULL)
    {
        perror(NULL);
        exit(1);
    }
    while(fgets(buff, BUFSIZ, fp_t) != NULL)
    {
//        buff[strlen(buff) - 1] = '\0';
        p = buff;
        sscanf(p, "%[^;]s", cin_stars[i].name);
        p += strlen(cin_stars[i].name) + 1;
        sscanf(p, "%[^;]s", str);
        x = atoi(str);
        cin_stars[i].age = x;
        p += strlen(str) + 1;
        sscanf(p, "%[^;]s", cin_stars[i].country);
        p += strlen(cin_stars[i].country) + 1;
        sscanf(p, "%[^;]s", str);
        x_ul = atoi(str);
        cin_stars[i].earned_money = x_ul;
        p += strlen(str) + 1;
        sscanf(p, "%s", str);
        x = atoi(str);
        cin_stars[i].num_of_oscars = x;
        i++;
    }
    free(buff);
    free(str);
}

void disp_info(CS *cin_stars, int cnt)
{
    for(int i = 0; i < cnt; i++)
    {
        printf("%s\n", cin_stars[i].name);
        printf("%d\n", cin_stars[i].age);
        printf("%s\n", cin_stars[i].country);
        printf("%lu\n", cin_stars[i].earned_money);
        printf("%d\n", cin_stars[i].num_of_oscars);
        NL;
    }
}
void ent_info(CS *cin_stars, int stars)
{
    for(int i = 0; i < stars; i++)
    {
        printf("Name of star: ");
        scanf("%s", cin_stars[i].name);
        printf("Age: ");
        scanf("%d", &cin_stars[i].age);
        printf("Country's star: ");
        scanf("%s", cin_stars[i].country);
        printf("Earned money: ");
        scanf("%lu", &cin_stars[i].earned_money);
        printf("Numbers of oscars won: ");
        scanf("%d", &cin_stars[i].num_of_oscars);
        NL;
    }
}

void add_new_artist(CS *cin_stars, int *stars)
{
    cin_stars = (CS *)realloc(cin_stars, sizeof(CS)*(*stars + 1));
    if(cin_stars == NULL)
    {
        perror(NULL);
        exit(1);
    }
    printf("Name of star: ");
    scanf("%s", cin_stars[*stars].name);
    printf("Age: ");
    scanf("%d", &cin_stars[*stars].age);
    printf("Country's star: ");
    scanf("%s", cin_stars[*stars].country);
    printf("Earned money: ");
    scanf("%lu", &cin_stars[*stars].earned_money);
    printf("Numbers of oscars won: ");
    scanf("%d", &cin_stars[*stars].num_of_oscars);
    (*stars)++;
    NL;
}

CS * certain_income_array(CS *cin_stars, unsigned long income, int stars)
{
    int cnt = 0, j = 0;
    for(int i = 0; i < stars; i++)
    {
        if(cin_stars[i].earned_money > income)
        {
            cnt++;
        }
    }
    CS *income_array = (CS *)malloc(sizeof(CS)*cnt);
    if(income_array == NULL)
    {
        perror(NULL);
        exit(1);
    }
    for(int i = 0; i < stars; i++)
    {
        if(cin_stars[i].earned_money > income)
        {
            income_array[j++] = cin_stars[i];
        }
    }

    return income_array;
}
int counter(CS *cin_stars, unsigned long income, int stars)
{
    int cnt = 0;
    for(int i = 0; i < stars; i++)
    {
        if(cin_stars[i].earned_money > income)
        {
            cnt++;
        }
    }
    return cnt;
}
#endif // EXAMPLE_TERM1_H_INCLUDED
