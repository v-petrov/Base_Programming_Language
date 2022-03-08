#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 3, y = 5, z;
// ++y;
// z = y + x;
// x++;
    z = ++y + x++;
    printf("x=%d, y=%d, z=%d", x,y,z);

    printf("-1<1: %s\n", (-1<1)?"true":"false");

    printf("-1<1: %s\n", (-1<1u)?"true":"false");
    printf("-1L<1: %s\n", (-1L<1)?"true":"false");
    printf("-1L<1UL %s\n", (-1L<1UL)?"true":"false");
    return 0;
}
