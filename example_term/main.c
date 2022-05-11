#include "EXAMPLE_TERM.h"

int main()
{
    int ng,g,num,ns,class_num;
    char s;
    int n;
    FILE *fp_t;
    fp_t = fopen("students.txt", "r");

    if(fp_t == NULL)
    {
        perror("Open error");
        exit(1);
    }

    n = counter_students(fp_t);
    student *st;
    st = (student *)malloc(n*sizeof(student));

    if(st == NULL)
    {
        perror(NULL);
        exit(1);
    }

    read_file(fp_t, st);
    fclose(fp_t);

    printf("Do you want to add new student/s(Y/N): ");
    scanf("%c", &s);
    if(s == 'Y' || s == 'y')
    {
        printf("How many do you want to add: ");
        scanf("%d", &ns);
        while(ns != 0)
        {
            add_student(st, &n);
            ns--;
        }
    }
    fflush(stdin);
    printf("Do you want to add new grade/s(Y/N): ");
    scanf("%c", &s);
    if(s == 'Y' || s == 'y')
    {
        printf("How many grades you wish to add: ");
        scanf("%d", &ng);
        fflush(stdin);
        while(ng != 0)
        {
            fflush(stdin);
            NL;
            printf("Enter a subject(M/B/I): ");
            scanf("%c", &s);
            printf("Enter the grade: ");
            scanf("%d", &g);
            fflush(stdin);
            printf("Enter the number of student: ");
            scanf("%d", &num);
            add_grade(s, g, num, st, n);
            ng--;
        }
    }
    NL;
    printf("Enter the class(3 digits) to see their average score: ");
    scanf("%d", &class_num);
    average_class(class_num, st, n);
    END(st, n);
    free(st);
    return 0;
}
