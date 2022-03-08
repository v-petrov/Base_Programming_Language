#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1001

//int main()
//{
//    char line[MAXSIZE];
//    char maxLine[MAXSIZE];
//
//    maxLine[0] = '\0';
//
//    while (fgets(line,MAXSIZE,stdin) != NULL)
//    {
//        if (strlen(line)>strlen(maxLine))
//        {
//            strcpy(maxLine,line);
//        }
//    }
////    puts(maxLine);
//    printf("Max line is: %s\nLength: %i\n", maxLine,(unsigned)strlen(maxLine));
//    return 0;
//}

int main()
{
    char v;
    int nc,i,nc1=0,j,k,e,z = 0,p;
    char line[MAXSIZE];
    char maxLine[MAXSIZE];

    maxLine[0] = '\0';

//    l = sizeof(maxLine) / sizeof(char);
//    printf("%d", l);

    printf("Tell us how many lines you are going to enter: ");
    scanf("%d", &e);

    for(j = 0; j <= e; ++j)
    {
        if(nc1 >= z)
        {
            z = nc1;
        }
        nc1=i=nc=0;
        while(((v = getchar()) != '\n') && i < MAXSIZE)
        {
            nc++;
            line[i] = v;
            i++;
        }
        for(k = 0;k < nc; ++k)
        {
            if(nc >= nc1)
            {
                nc1++;
                maxLine[k] = line[k];
            }
        }
        for(p = 0; p<nc; ++p)
        {
            line[p] = '\0';
        }
    }
    if(nc1 >= z)
    {
        z = nc1;
    }
    printf("%s\t %d", maxLine, z);
    return 0;
}
