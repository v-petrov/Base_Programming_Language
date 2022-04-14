#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int size = 50 * sizeof(char);
    char *BIG_str, *str;
    BIG_str = (char *)malloc(size);
    str = (char *)malloc(size);
    fgets(str, size, stdin);
    strcpy(BIG_str, str);
    while(1)
    {
        fgets(str, size, stdin);
        if(!strcmp(str, "quit\n\0") || strlen(BIG_str) + strlen(str) > size)
        {
            break;
        }
        strcat(BIG_str, str);
    }

    printf("\n%s\n", BIG_str);

    return 0;
}
