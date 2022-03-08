#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE !TRUE
#define BOOLEAN int


/*int main()
{
    short temp;
    short sum=0;
    short cnt=0;
    short minTemp;
    short maxNegTemp=SHRT_MIN;
    short dateNo = -1;
    BOOLEAN isInit=FALSE;

    do {
        printf("Temp: ");
        scanf("%hi", &temp);
        if (!temp)
        {
            break;
        }
        if (!isInit)
        {
            minTemp = temp;
            isInit = !isInit; // isInit = TRUE;
        }
        else if (minTemp > temp)
        {
            minTemp = temp;
        }
        if (temp < 0 && maxNegTemp < temp)
        {
            maxNegTemp = temp;
            dateNo = cnt+1;
        }
        sum += temp;
        cnt++;
    } while (TRUE);

    if (!cnt) // cnt == 0
    {
        printf("No data...\n");
    }
    else
    {
        printf("Average T: %g\n", (float)sum/cnt);
        printf("Min T: %hi\n", minTemp);
        if (dateNo == -1)
        {
            printf("No negative T\n");
        }
        else
        {
            printf("Max Neg T: %hi\t Day: %hi\n", maxNegTemp, dateNo);
        }
    }
    return 0;
}*/

#include <time.h>

#define SIZE 10

int main()
{
    int i;
    short sum = 0;
    short num;
    short minEvenNum;
    BOOLEAN isInit = FALSE;

    srand(time(NULL));

    for(i = 0; i < SIZE; ++i)
    {
        num = (short)(rand() % 50 - 25);
        printf("%hi ", num);
        sum += num;
        if (num % 2 == 0)
        {
            if(!isInit)
            {
                minEvenNum = num;
                isInit = !isInit; // isInit = TRUE
            }
            else if (minEvenNum > num)
            {
                minEvenNum = num;
            }
        }
    }
    printf("\nSum = %hi\n", sum);
    if (!isInit)
    {
        printf("No even numbers....\n");
    }
    else
    {
        printf("Min even number: %hi\n", minEvenNum);
    }
    return 0;
}
