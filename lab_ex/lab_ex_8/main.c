#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int polindrom(char *);

int main()
{
//    //#1 - dynamically allocated memory for char array, itre the stingto find first interval - print after first interval
//    char *str, ws = ' ';
//    int i = 0;
//    str = (char*)malloc(100*sizeof(char));
//    printf("Enter text: ");
//    scanf("%[^\n]s", str);
//
//    while(i < strlen(str))
//    {
//        if(str[i]  == ws)
//        {
//            printf("The rest of the text: ");
//            while(i < strlen(str))
//            {
//                printf("%c", str[i+1]);
//                i++;
//            }
//        }
//        else
//        {
//            i++;
//        }
//    }

//    //#2 - print string backwards
//    char *str;
//    str = (char*)malloc(100*sizeof(char));
//    printf("Enter text: ");
//    scanf("%[^\n]s", str);
//
//    printf("Opposite text: ");
//    for(int i = strlen(str) - 1; i >= 0; i--)
//    {
//        printf("%c", str[i]);
//    }

//    //#3 - print count (, . -)
//    char *str;
//    str = (char*)malloc(100*sizeof(char));
//    printf("Enter text: ");
//    scanf("%[^\n]s", str);
//    char dot = '.', comma = ',', ws = ' ';
//    int c_dot, c_comma, c_ws;
//    c_dot = c_comma = c_ws = 0;
//
//
//    for(int i = 0; i < strlen(str); i++)
//    {
//        if(str[i] == dot)
//        {
//            c_dot++;
//        }
//        else if(str[i] == comma)
//        {
//            c_comma++;
//        }
//        else if(str[i] == ws)
//        {
//            c_ws++;
//        }
//    }
//
//    printf("\nThe count of the '.' is: %d\n\n", c_dot);
//    printf("The count of the ',' is: %d\n\n", c_comma);
//    printf("The count of the ' ' is: %d\n\n", c_ws);

    //#4 - char[bigger size] concetenate n-count string input "quit" || bigstr.size < bigstr.size+new_str
//    int size = 50 * sizeof(char);
//    char *BIG_str, *str;
//    BIG_str = (char *)malloc(size);
//    str = (char *)malloc(size);
//    fgets(str, size, stdin);
//    strcpy(BIG_str, str);
//    while(1)
//    {
//        fgets(str, size, stdin);
//        if(!strcmp(str, "quit\n\0") || strlen(BIG_str) + strlen(str) > size)
//        {
//            break;
//        }
//        strcat(BIG_str, str);
//    }
//
//    printf("\n%s\n", BIG_str);

    //#5 - checking for a polindrom
//    char *str;
//    str = (char*)malloc(25*sizeof(char));
//    printf("Enter a word: ");
//    scanf("%[^\n]s", str);
//    fflush(stdin);
//    printf("%d ", polindrom(str));

    //#6 - guessing the word
    char word[] = "tottenham";
    char guess[] = "_________";
    int cnt_;

    while(1)
    {
        char c;
        printf("Input a char: ");
        scanf("%c", &c);
        fflush(stdin);

        for(int i = 0; i < strlen(word); i++)
        {
            if(c == word[i])
            {
                guess[i] = c;
            }
        }

        printf("%s\n", guess);

        for(int i = 0; i < strlen(guess); i++)
        {
            cnt_ = 0;
            if('_' == guess[i])
            {
                cnt_++;
                break;
            }
        }

        if(!cnt_)
        {
            printf("\nCongratulations, You have guessed the word!\n");
            break;
        }
    }
    return 0;
}

int polindrom(char *s)
{
    int cnt = 0, j = strlen(s);
    for(int i = 0; i < strlen(s) / 2; i++)
    {
        if(s[i] == s[j - 1])
        {
            cnt++;
            j--;
        }
    }

    if(cnt == strlen(s) / 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
