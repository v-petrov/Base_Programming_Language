#ifndef LAB_EX_10_H_INCLUDED
#define LAB_EX_10_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

void build_up()
{
//    char ch;
//    FILE *fp = fopen("upr.txt","w");
//    if(fp == NULL)
//    {
//        perror("can't open the file");
//        exit(1);
//    }
    //int//fgetc(fp) if error or end of file'EOF';
    //int//fputc(int ch, fp) if error 'EOF';

    //int//feof(fp) not 0 if reached EOF, otherwise 0;
    //int//ferrorr(fp) not 0 if reached error, otherwise 0;
//
//    while(!feof(fp))
//    {
//        ch = fgetc(fp);
//        if(ferror(fp))
//        {
//            printf("Error");
//            fclose(fp);
//            break;
//        }
//    }

    //fgets(str, num-1, fp) NULL if unsuccessfull;
    //fputs(str, fp) no new line after execution;

    //fprintf(fp, "format spec", arg);
    //fscanf(fp, "format spec", &arg);

    //fread(void* buffer, size_t size, size_t num, FILE *fp);
    //fwrite(void* buffer, size_t size, size_t num, FILE *fp);

    //fclose(fp);

//    FILE *fp;
//    int y = 123;
//    int y1;
//    fp = fopen("myfile", "wb");
//    if(fp == NULL)
//    {
//        printf("Error opening");
//        exit(1);
//    }
//    if(fwrite(&y, sizeof(int), 1, fp) != 1)
//    {
//        printf("Error with writing");
//        exit(2);
//    }
//
//    fclose(fp);
//
//    fp = fopen("myfile", "rb");
//    if(fp == NULL)
//    {
//        printf("Error opening");
//        exit(1);
//    }
//
//    if(fread(&y1, sizeof(int), 1, fp) != 1)
//    {
//        printf("Error with writing");
//        exit(2);
//    }
//    printf("y1 = %d", y1);

    //fseek(FILE *fp, offset[num of bytes], beggining[SEEK_SET, SEEK_CUR, SEEK_END]);
    //long//ftell(fp);
    //void//rewind(fp);
    //fflush(fp) 0 if successfull, otherwise EOF;
}

void ex_1()
{
    //fprintf, fscnaf
    int x = 5;
    float x_f = 5.5;
    char str[] = "Vasko";
    FILE *fp;
    fp = fopen("task1","w");
    if(fp == NULL)
    {
        perror("Error opening");
        exit(1);
    }

    fprintf(fp, "%d\t%f\t%s", x, x_f, str);
    fclose(fp);

    int y;
    float y_f;
    char y_str[11];
    fp = fopen("task1","r");
    if(fp == NULL)
    {
        perror("Error opening");
        exit(1);
    }

    fscanf(fp, "%d %f %s", &y, &y_f, y_str);
    printf("y = %d\n", y);
    printf("y_f= %.2f\n", y_f);
    printf("y_str = %s\n", y_str);
}

void ex_2()
{
    //масив с дробни числа 10 елем, инит, записваме във файл масива, fwrite запис, кой елемент да се прочете въвеждане и принтираме
    float nums[] = {5.5, 5.6, 5.7, 5.8, 5.9, 6.1, 6.2, 6.3, 6.4, 6.5};
    FILE *fp;
    fp = fopen("task2","wb");
    if(fp == NULL)
    {
        perror("Error opening");
        exit(1);
    }

    if(fwrite(nums, sizeof(nums), 1, fp) != 1)
    {
        perror("Error writing");
        exit(1);
    }

    fclose(fp);

    fp = fopen("task2","rb");
    if(fp == NULL)
    {
        perror("Error opening");
        exit(1);
    }

    int pos;
    float num;
    printf("Pos: ");
    scanf("%d", &pos);

    fseek(fp, (pos-1)*sizeof(float), SEEK_SET);
    if(fread(&num, sizeof(num), 1, fp) != 1)
    {
        perror("Error writing");
        exit(1);
    }
    printf("Element: %.2f", num);
}
#endif // LAB_EX_10_H_INCLUDED
