#include "sem_ex_3.h"

int main()
{
    //#1
    int n, temp, cnt = 0, t = 0, cnt1 = 0;
    printf("N: ");
    scanf("%d", &n);
    int numbers[n];
    int sequance[n];

    srand(time(NULL));

    for(int i = 0; i < n; i++)
    {
        numbers[i] = rand() % 15;
    }

    for(int j = 0; j < n - 1; j++)
    {
        for(int k = j + 1; k < n; k++)
        {
            if(numbers[j] > numbers[k])
            {
                temp = numbers[j];
                numbers[j] = numbers[k];
                numbers[k] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }

    for(int i = 0; i < n; i++)
    {
        if(numbers[i] != numbers[i + 1])
        {
            sequance[t] = cnt;
            cnt = 0;
            cnt1++;
            t++;
        }
        else
        {
            while(numbers[i] == numbers[i + 1])
            {
                if(!cnt)
                {
                    cnt++;
                }
                cnt++;
                break;
            }
        }
    }
    printf("\n");

    int max = sequance[0];
    for(int i = 0; i < cnt1; i++)
    {
        if(max < sequance[i])
        {
            max = sequance[i];
        }
    }

    printf("The longest row of equal numbers is: %d", max);

    //#2
    int n;
    printf("N: ");
    scanf("%d", &n);
    int numbers[n];

    srand(time(NULL));

    for(int i = 0; i < n; i++)
    {
        numbers[i] = rand() % 15;
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    for(int j = 0; j < n; j+=2)
    {
        if(numbers[j] < numbers[j+1] && numbers[j+1] > numbers[j+2])
        {
            printf("True\n");
        }
        else
        {
            printf("False\n");
        }
    }

    //#3
    int n,p,temp;
    printf("N: ");
    scanf("%d", &n);
    int numbers[n];
    p = n;

    srand(time(NULL));

    for(int i = 0; i < n; i++)
    {
        numbers[i] = rand() % 15;
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    for(int i = 0; i < n/2; i++)
    {
        temp = numbers[i];
        numbers[i] = numbers[p - 1];
        numbers[p - 1] = temp;
        p--;
    }
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }

    //#4
    int n,k,temp,temp1;
    printf("N: ");
    scanf("%d", &n);
    int numbers[n];
    printf("K: ");
    scanf("%d", &k);

    srand(time(NULL));

    for(int i = 0; i < n; i++)
    {
        numbers[i] = rand() % 15;
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    for(int j = 1; j <= k; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(!i)
            {
                temp = numbers[i];
                numbers[i] = numbers[n - 1];
            }
            else
            {
                temp1 = numbers[i];
                numbers[i] = temp;
                temp = temp1;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }

    //#5
    int n,k,temp, max_3, cnt = 0;
    printf("N: ");
    scanf("%d", &n);
    int numbers[n];
    printf("K: ");
    scanf("%d", &k);

    srand(time(NULL));

    for(int i = 0; i < n; i++)
    {
        numbers[i] = rand() % 15;
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    for(int j = 0; j < n - 1; j++)
    {
        for(int k = j + 1; k < n; k++)
        {
            if(numbers[j] < numbers[k])
            {
                temp = numbers[j];
                numbers[j] = numbers[k];
                numbers[k] = temp;
            }
        }
    }

    max_3 = numbers[0];
    for(int i = 0; i < n; i++)
    {
        if(cnt == k - 1)
        {
            break;
        }
        if(max_3 > numbers[i])
        {
            max_3 = numbers[i];
            cnt++;
        }
    }

    printf("The %d biggest element is: %d", k, max_3);

    return 0;
}
