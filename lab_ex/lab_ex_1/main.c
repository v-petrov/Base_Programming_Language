#include <stdio.h>
#include <stdlib.h>

int main()
{
//    int a,b;
//    char one = '1';
//    char a = 'a';
//    printf("%d \n", one);
//    printf("%d \n", one+1);
//    printf("%d \n", one+2);
//    printf("%d \n", one+3);
//    printf("%d \n", a);
//    printf("%d \n", a+1);
//    printf("%d \n", a+2);
//    printf("%d \n", a+3);
//    printf("%d", sizeof(int));

//    printf("Enter A: ");
//    scanf("%d", &a);
//    printf("Enter B: ");
//    scanf("%d", &b);
//    printf("The S: %d", a*b);

    int a, b;
    printf("Enter A: "); // a = 3
    scanf("%d", &a);
    printf("Enter B: "); // b = 7
    scanf("%d", &b);

    a += b;
    b = a - b;
    a -= b;
    printf("New A is B: %d\n", a);
    printf("New B is A: %d", b);
    return 0;
}
