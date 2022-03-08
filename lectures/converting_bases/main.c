#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 11

void convert_numerical_system(unsigned base_10, char *s, unsigned base);
void convert_string(char *s1, char *s2);


int main()
{
    unsigned base_10, base;
    char s[SIZE];
    printf("Enter number is decimal numerical system: ");
    scanf("%u", &base_10);
    printf("Enter base in which the number is going to be converted: ");
    scanf("%u", &base);

    convert_numerical_system(base_10,s,base);
//    char s1[SIZE*2], s2[] = {"Some random text\tin the array\n\n!!!"};
//
//    convert_string(s1,s2);
//    puts(s2);
//    puts(s1);
    return 0;
}

void convert_numerical_system(unsigned base_10, char *s, unsigned base)
{
    char remainder;
    int cnt = 0;
    int i = 0;
    s[SIZE] = '\0';

    if(base_10 == 0)
    {
        printf("Your number in %d base is: %d", base, base_10);
    }

    while(base_10 > 0)
    {
        remainder = base_10 % base;

        if(remainder > 9)
        {
            remainder += '7';
        }
        else
        {
            remainder += '0';
        }
        s[i] = remainder;
        i++;
        base_10 /= base;
        cnt++;
    }
    int temp,p;
    p = cnt - 1;
    for(int i = 0; i < (cnt / 2); ++i)
    {
        temp = s[i];
        s[i] = s[p];
        s[p] = temp;
        p--;
    }
    for(int j = 0; j < cnt; ++j)
    {
        printf("%c", *(s + j));
    }
}

void convert_string(char *s1, char *s2)
{
    int i,j;
    for(i=j=0; i < strlen(s2); i++)
    {
        switch(s2[i])
        {
            case '\n':
                s1[j++] = '\\';
                s1[j++] = 'n';
                break;
            case '\t':
                s1[j++] = '\\';
                s1[j++] = 't';
                break;
            default:
                s1[j++] = s2[i];
        }
    }
    s1[j] = '\0';
}
