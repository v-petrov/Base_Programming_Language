#ifndef EXAMPLE_TERM_H_INCLUDED
#define EXAMPLE_TERM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NL printf("\n")
#define NAME_SIZE 15
#define GRADE_SIZE 10

typedef struct Subjects
{
    int mark;
}subject;

typedef struct Student
{
   char f_name[NAME_SIZE + 1];
   char s_name[NAME_SIZE + 1];
   char t_name[NAME_SIZE + 1];
   int num_in_class;
   subject math[GRADE_SIZE];
   subject bg[GRADE_SIZE];
   subject it[GRADE_SIZE];
}student;

//int n;
int m,b,i;

int counter_students(FILE *fp_t);
void read_file(FILE *fp_t, student *st);
void print_struct(student *st, int n);
void add_grade(char s, int grade, int number, student st[], int n);
void average_class(int class_num, student *st, int n);
int counter_grade(student st[], int p, char c);
void add_student(student st[], int *n);
void END(student st[], int n);


#endif // EXAMPLE_TERM_H_INCLUDED
