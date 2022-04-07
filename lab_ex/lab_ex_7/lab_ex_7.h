#ifndef LAB_EX_7_H_INCLUDED
#define LAB_EX_7_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_len(char *s)
{
    int cnt = -1, i = 0;
    while(*(s + i) != '\0')
    {
        cnt++;
        i++;
    }
    return cnt;
}
void str_cmp(char*s1, char*s2, int len, int len1)
{
    int cnt = 0;

    if(len == len1)
    {
        for(int i = 0; i < len; i++)
        {
            if(s1[i] == s2[i])
            {
                cnt++;
            }
        }

        if(cnt == len)
        {
            printf("The strings are equal!");
        }
        else
        {
            printf("The strings are not equal!");
        }
    }
    else
    {
        printf("The strings are not equal!");
    }
}
int word_cnt_1(char*s, int len)
{
    char ws = ' ';
    int cnt, i  = 0, w_cnt = 0;
    while(i < len)
    {
        cnt = 0;
        while(s[i] != ws && i < len)
        {
            cnt++;
            i++;
        }
        if(cnt > 0)
        {
            w_cnt++;
        }
        else
        {
            i++;
        }
    }

    return w_cnt;
}
#endif // LAB_EX_7_H_INCLUDED
