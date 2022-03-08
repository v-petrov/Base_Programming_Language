#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    while (c != EOF) // EOF = ^Z
    {
        c = getchar();
        putchar(c);
    }
}
