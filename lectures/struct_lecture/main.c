#include "struct.h"

int main()
{
    TStudent st1, *st2, group[3];

//    st1 = input();
//    print(st1);

//    st2 = (TStudent*)malloc(sizeof(TStudent));
//
//    if(st2 == NULL)
//    {
//        printf("Error in memory allocation!");
//        return EXIT_FAILURE;
//    }
//    *st2 = input();
//    print(*st2);
//
//    free(st2);

    input_group(group, 3);
    print_group(group, 3);
    printf("Average mark: %g", average_mark(group, 3));

    return 0;
}
