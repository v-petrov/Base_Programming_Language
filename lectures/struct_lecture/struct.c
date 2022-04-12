#include "struct.h"

struct TTStudent input()
{
    TStudent st;

    printf("Faculty Number: ");
    scanf("%u",&st.f_num);
    printf("Name: ");
    scanf("%s",st.name);
    printf("Average Mark: ");
    scanf("%f",&st.mark);

    return st;
}

void print(TStudent st)
{
    printf("%u, %s, %g\n", st.f_num, st.name, st.mark);
}

void input_group(TStudent *group, unsigned len)
{
    for(int i = 0; i < len; i++)
    {
        group[i] = input();
    }
}

void print_group(TStudent *group, unsigned len)
{
    for(int i = 0; i < len; i++)
    {
        print(group[i]);
    }
}

float rounding(float data, unsigned dec)
{
    float nom = pow(10, dec);
    return ((int)(data*nom+0.5))/nom;
}

float average_mark(TStudent *group, unsigned len)
{
    float sum = 0;
    for(int i = 0; i < len;i++)
    {
        sum += group[i].mark;
    }

    return (!len) ? 0 : rounding(sum/len, 2);
}
