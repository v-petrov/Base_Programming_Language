#ifndef ARRAY_H_H_INCLUDED
#define ARRAY_H_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

void random_array(int *, unsigned);
void display_array(int *, unsigned);
unsigned fill_array(int data[], int sort[], unsigned size);
int first_digit(int n);
int last_digit(int n);
unsigned fill_array_f_l(int data[], int sort[], unsigned size);

#endif // ARRAY_H_H_INCLUDED
