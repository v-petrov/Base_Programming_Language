#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef enum {False, True} TBoolean;

void copy_file(char *src, char *dest)
{
    char c;
    FILE *in, *out;

    in = fopen(src, "r");
    if(in == NULL)
    {
        perror("open source file");
        exit(EXIT_FAILURE);
    }
    out = fopen(dest, "w");
    if(out == NULL)
    {
        perror("open source file");
        exit(EXIT_FAILURE);
    }

    while((c = fgetc(in)) != EOF)
    {
        fputc(c, out);
    }

    fclose(in);
    fclose(out);
}

void cat_file(char *src, char *dest)
{
    FILE *in, *out;
    char buff[BUFSIZ];

    in = fopen(src, "r");
    if(in == NULL)
    {
        perror("open source file");
        exit(EXIT_FAILURE);
    }
    out = fopen(dest, "w");
    if(out == NULL)
    {
        perror("open source file");
        exit(EXIT_FAILURE);
    }

    while((fgets(buff, BUFSIZ, in))!= NULL)
    {
        fputs(buff, out);
        puts(buff);
    }

    fclose(in);
    fclose(out);
}

int read_temp(char *fname, double *temp)
{
    FILE *in;
    int len = 0;
    in = fopen(fname, "r");
    if(in == NULL)
    {
        perror(NULL);
        exit(errno);
    }

    while(True)
    {
        if(fscanf(in, "%lf", &temp[len]) != 1)
        {
            if(feof(in))
            {
                fclose(in);
                return len;
            }
            else
            {
                perror(NULL);
                fclose(in);
                exit(errno);
            }
        }
        len = (len+1) % MAXSIZE;
    }
    fclose(in);
}

void print(double *temp, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%g ", *(temp + i));
    }
}

int main()
{
    double temp_data[MAXSIZE];
    int len;

    len = read_temp("temps.txt", temp_data);
    print(temp_data, len);
    //copy_file("lipsum.txt","lipsum_out.txt");
    //cat_file("lipsum.txt","lipsum_out_1.txt");
    return 0;
}
