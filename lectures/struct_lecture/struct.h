#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct TTStudent
{
    unsigned f_num;
    char name[30];
    float mark;
};

typedef struct TTStudent TStudent;

struct TTStudent input();
void print(TStudent st);
void input_group(TStudent *group, unsigned len);
void print_group(TStudent *group, unsigned len);
float average_mark(TStudent *group, unsigned len);
float rounding(float data, unsigned dec);
#endif // STRUCT_H_INCLUDED
