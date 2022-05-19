#ifndef LAB_EX_11_H_INCLUDED
#define LAB_EX_11_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int num_of_words(FILE *fp);
int num_of_sentences(FILE *fp);

void ex_1()
{
    FILE *fp_t;
    char line_in[51];
    char line_out[51];
    int j = 1;
    fp_t = fopen("file1.txt", "w");
    if(fp_t == NULL)
    {
        perror("Error open");
        exit(1);
    }
    for(int i = 0; i < 5; i++)
    {
        printf("Line #%d: ", i + 1);
        fgets(line_in, sizeof(line_in), stdin);
        fputs(line_in,fp_t);
    }
    fclose(fp_t);
    fp_t = fopen("file1.txt", "r");
    if(fp_t == NULL)
    {
        perror("Error open");
        exit(1);
    }
    printf("\n\n");
    while(fgets(line_out, sizeof(line_out), fp_t) != NULL)
    {
        printf("Line #%d: %s", j, line_out);
        j++;
    }
}

void ex_2()
{
    FILE *fp_b;
    int n, pos;
    srand(time(NULL));
    fp_b = fopen("file2_b", "wb");

    if(fp_b == NULL)
    {
        perror("Error open");
        exit(1);
    }
    for(int i = 1; i <= 50; i++)
    {
        n = i;
        if(fwrite(&n, sizeof(n), 1, fp_b) != 1)
        {
            perror("Error write");
            exit(2);
        }
    }

    fclose(fp_b);

    fp_b = fopen("file2_b", "rb");
    if(fp_b == NULL)
    {
        perror("Error open");
        exit(1);
    }

    printf("Position of the number: ");
    scanf("%d", &pos);
    int num;

    fseek(fp_b, (pos - 1)*sizeof(int), SEEK_SET);

    if(fread(&num, sizeof(num), 1, fp_b) != 1)
    {
        perror("Error writing");
        exit(1);
    }
    fclose(fp_b);
    printf("n = %d", num);

}

void ex_3()
{
    FILE *fp_t;
    fp_t = fopen("file3.txt", "r");
    int w_cnt, s_cnt;
    if(fp_t == NULL)
    {
        perror("Error open");
        exit(1);
    }
    w_cnt = num_of_words(fp_t);
    printf("w_cnt = %d\n", w_cnt);
    rewind(fp_t);
    s_cnt = num_of_sentences(fp_t);
    printf("s_cnt = %d\n", s_cnt);
}

int num_of_words(FILE *fp)
{
    int cnt, i, w_cnt = 0;
    char buff[BUFSIZ];
    while(fgets(buff,BUFSIZ, fp) != NULL)
    {
        buff[strlen(buff) - 1] = '\0';
        i = 0;
        while(i < strlen(buff))
        {
            cnt = 0;
            while((buff[i] != ' ' && buff[i] != ',' && buff[i] != '.') && i < strlen(buff))
            {
                cnt++;
                i++;
            }
            if(cnt > 0)
            {
                w_cnt++;
            }
            else
            {
                i++;
            }
        }
    }
    return w_cnt;
}
int num_of_sentences(FILE *fp)
{
    int s_cnt = 0, i;
    char buff[BUFSIZ];
    while(fgets(buff, BUFSIZ, fp) != NULL)
    {
        i = 0;
        while(i < strlen(buff))
        {
            if(buff[i] == '.' && buff[i+1] != '.')
            {
                s_cnt++;
                i++;
            }
            else if(buff[i] == '!' && buff[i+1] != '!')
            {
                s_cnt++;
                i++;
            }
            else if(buff[i] == '?' && buff[i+1] != '?')
            {
                s_cnt++;
                i++;
            }
            else
            {
                i++;
            }
        }

    }
    return s_cnt;
}

void ex_4()
{
    int N, n, cnt_even = 0, cnt_odd = 0;
    printf("Enter N: ");
    scanf("%d", &N);

    FILE *fp_b;
    srand(time(NULL));

    if((fp_b = fopen("file4_b", "wb")) == NULL)
    {
        perror("Error open");
        exit(1);
    }

    for(int i = 0; i < N; i++)
    {
        n = rand() % 50;
        if(fwrite(&n, sizeof(int), 1, fp_b) != 1)
        {
            perror("Error fwrite");
            exit(3);
        }
    }
    fclose(fp_b);

    if((fp_b = fopen("file4_b", "rb")) == NULL)
    {
        perror("Error read");
        exit(4);
    }

    for(int i = 0; i < N; i++)
    {
        if(fread(&n, sizeof(int), 1, fp_b) != 1)
        {
            perror("Error fread");
            exit(5);
        }
        if(n % 2 == 0)
        {
            cnt_even++;
        }
        else
        {
            cnt_odd++;
        }
    }

    printf("Even numbers: %d\nOdd numbers: %d", cnt_even, cnt_odd);
    fclose(fp_b);

    FILE *fp_txt;

    if((fp_b = fopen("file4_b", "rb")) == NULL)
    {
        perror("Error read1");
        exit(1);
    }

    int nums[N];

    for(int i = 0; i < N; i++)
    {
        if(fread(&n, sizeof(int), 1, fp_b) != 1)
        {
            perror("Error fread1");
            exit(5);
        }
        nums[i] = n;
    }
    fclose(fp_b);
    int temp;
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            if(nums[i] > nums[j])
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    if((fp_txt = fopen("file4.txt", "w")) == NULL)
    {
        perror("Error open txt");
        exit(1);
    }

    for(int i = 0; i < N; i++)
    {
        fprintf(fp_txt, "%d ", nums[i]);
    }
    fclose(fp_txt);
}
#endif // LAB_EX_11_H_INCLUDED
