#include "lab_ex_7.h"

int main()
{
//    char s[80] = "Hello World"; // '\0' at the end
//    char s1[20] = {'H', 'e', 'l', 'l', 'o', '\0'};
//    char s2[100];
//    printf("%s\n", s);
//    printf(s);
//    printf("\n");
//    puts(s);
//    printf("%c\n", *s1);
//
//    for(int i = 0; s1[i]; i++)
//    {
//        printf("%c", *(s1 + i));
//    }
//
//    scanf("%s", s2);
//    scanf("%[^\n]s", s2); // reads everything but the new line
//
//    // fgets(str, sizeof(str), stdin);
//
//    // strcpy(s1, s2); s2 into s1, s2 doesnt change
//    // strcat(s1, s2); s2 goes behind s1, s2 doesnt change
//    // strlen(s1);
//    // strcmp(s1, s2); returns 0 if s1=s2, <0 if s1<s2, >0 if s1>s2

    //#1
    char s1[20] = "Hello";
    char s2[20] = "HelloV";
    int i, len;

    i = strcmp(s1,s2);
    printf("%d\n", i);

    strcpy(s1, s2);

    i = strcmp(s1,s2);
    printf("%d\n", i);

    len = strlen(s1);
    printf("%d\n", len);

    strcat(s1, s2);

    len = strlen(s1);
    printf("%d\n", len);

    //#2
    char str[100];
    fgets(str, sizeof(str), stdin); // contains all the chars +  the '\0' terminator
//    scanf("%[^\n]s", str);
    int len;

    len = str_len(str);

    printf("Len is: %d", len);

    //#3
    char str[100];
    fgets(str, sizeof(str), stdin); // contains all the chars +  the '\0' terminator
    int len,w_cnt;

    len = str_len(str);
    w_cnt = word_cnt_1(str, len);

    printf("Words in the string: %d", w_cnt);

    //#4
    printf("Enter s1: ");
    char s1[100];
    fgets(s1, sizeof(s1), stdin); // contains all the chars +  the '\0' terminator
    printf("Enter s2: ");
    char s2[100];
    fgets(s2, sizeof(s2), stdin);
    int len, len1;

    len = str_len(s1);
    len1 = str_len(s2);

    str_cmp(s1, s2, len, len1);

    return 0;
}
