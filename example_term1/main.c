#include "example_term1.h"

int main()
{
    int stars;
    int num_of_stars, cnt;
    char c;
    FILE *fp_t = fopen("stars.txt", "r");
    if(fp_t == NULL)
    {
        perror("Error open");
        exit(1);
    }
    stars = stars_cnt(fp_t);

    CS *cin_stars, *income_stars;
    cin_stars = (CS *)malloc(sizeof(CS)*stars);
    if(cin_stars == NULL)
    {
        perror(NULL);
        exit(1);
    }
    fflush(stdin);

    fill_info(fp_t, cin_stars);
    fclose(fp_t);

    printf("Do you want to add another/s star(Y/N): ");
    fflush(stdin);
    scanf("%c", &c);
    if(c == 'Y' || c == 'y')
    {
        printf("How many you wish to add: ");
        scanf("%d", &num_of_stars);
        while(num_of_stars != 0)
        {
            add_new_artist(cin_stars, &stars);
            num_of_stars--;
        }
    }

    income_stars = certain_income_array(cin_stars, 10000000, stars);

    cnt = counter(cin_stars, 10000000, stars);

    printf("Income array:\n\n");
    for(int i = 0; i < cnt; i++)
    {
        printf("%s\n", income_stars[i].name);
        printf("%d\n", income_stars[i].age);
        printf("%s\n", income_stars[i].country);
        printf("%lu\n", income_stars[i].earned_money);
        printf("%d\n", income_stars[i].num_of_oscars);
        NL;
    }

    printf("Information for all the artists: \n\n");
    disp_info(cin_stars, stars);

    free(cin_stars);
    free(income_stars);

    return 0;
}
