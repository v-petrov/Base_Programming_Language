#include "EXAMPLE_TERM.h"

int counter_students(FILE *fp_t)
{
    int len = 0;
    char buff[BUFSIZ];
    while(fgets(buff, BUFSIZ, fp_t) != NULL)
    {
        len++;
    }
    rewind(fp_t);
    return len;
}
void read_file(FILE *fp_t, student *st)
{
    // 17113: Ivan Ivanov Ivanov; Mat: 6 6 6 BG: 6 5 6 4 4 IT: 6 3
    char buff[BUFSIZ];
    char *p;
    int i = 0, j;
    while(fgets(buff, BUFSIZ, fp_t) != NULL)
    {
        p = buff;
        sscanf(p, "%d", &st[i].num_in_class);
        p += 7;
        sscanf(p, "%s %s %s", st[i].f_name, st[i].s_name, st[i].t_name);
        st[i].t_name[strlen(st[i].t_name) - 1] = '\0';
        p += strlen(st[i].f_name) + strlen(st[i].s_name) + strlen(st[i].t_name) + 9;
        j = 0;
        while(*p >= '2' && *p <= '6')
        {
            st[i].math[j++].mark = *p - '0';
            p += 2;
        }
        p += 4;
        j = 0;
        while(*p >= 50 && *p <= 54)
        {
            st[i].bg[j++].mark = *p - '0';
            p += 2;
        }
        p += 4;
        j = 0;
        while(*p >= 50 && *p <= 54)
        {
            st[i].it[j++].mark = *p - '0';
            p += 2;
        }
        i++;
    }
}
void print_struct(student *st, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d: %s %s %s;", st[i].num_in_class, st[i].f_name, st[i].s_name, st[i].t_name);
        printf(" Mat: %d %d %d", st[i].math[0].mark, st[i].math[1].mark, st[i].math[2].mark);
        printf(" BG: %d %d %d %d %d", st[i].bg[0].mark, st[i].bg[1].mark, st[i].bg[2].mark, st[i].bg[3].mark, st[i].bg[4].mark);
        printf(" IT: %d %d", st[i].it[0].mark, st[i].it[1].mark);
    }
}
void add_grade(char s, int grade, int number, student *st, int n)
{
    int ff = 0;
    for(int p = 0; p < n; p++)
    {
        if(number == st[p].num_in_class)
        {
            ff = 1;
            if(s == 'M')
            {
                m = counter_grade(st, p, s);
                st[p].math[m].mark = grade;
                m++;
                st[p].math[m].mark = 0;
            }
            else if(s == 'B')
            {
                b = counter_grade(st, p, s);
                st[p].bg[b].mark = grade;
                b++;
                st[p].bg[b].mark = 0;
            }
            else if(s == 'I')
            {
                i = counter_grade(st, p, s);
                st[p].it[i].mark = grade;
                i++;
                st[p].it[i].mark = 0;
            }
            else
            {
                printf("No such subject\n");
            }
        }
    }
    if(!ff)
    {
        printf("There is not a student with that number\n");
    }
}
void average_class(int class_num, student *st, int n)
{
    int n_num, cnt_mat, cnt_bg, cnt_it, cnt_st = 0;
    float average_math, average_bg, average_it;
    float average_math_cl = 0, average_bg_cl = 0, average_it_cl = 0;
    for(int i = 0; i < n; i++)
    {
        average_math = 0, average_bg = 0, average_it = 0;
        n_num = st[i].num_in_class / 100;
        if(class_num == n_num)
        {
            cnt_st++;
            cnt_mat = counter_grade(st, i, 'M');
            for(int j = 0; j < cnt_mat; j++)
            {
                average_math += st[i].math[j].mark;
            }
            average_math /= cnt_mat;
            cnt_bg = counter_grade(st, i, 'B');
            for(int j = 0; j < cnt_bg; j++)
            {
                average_bg += st[i].bg[j].mark;
            }
            average_bg /= cnt_bg;
            cnt_it = counter_grade(st, i, 'I');
            for(int j = 0; j < cnt_it; j++)
            {
                average_it += st[i].it[j].mark;
            }
            average_it /= cnt_it;
        }
        average_math_cl += average_math;
        average_bg_cl += average_bg;
        average_it_cl += average_it;
    }
    if(!cnt_st)
    {
        printf("No such class!\n");
    }
    else
    {
        average_math_cl /= cnt_st;
        average_bg_cl /= cnt_st;
        average_it_cl /= cnt_st;
        printf("Class %d:\n", class_num);
        printf("Mat average: %.2f\n", average_math_cl);
        printf("BG average: %.2f\n", average_bg_cl);
        printf("IT average: %.2f\n", average_it_cl);
    }
}
int counter_grade(student *st, int p, char c)
{
    int k = 0, cnt = 0;
    if(c == 'M')
    {
        while(st[p].math[k].mark != 0)
        {
            cnt++;
            k++;
        }
    }
    else if(c == 'B')
    {
        while(st[p].bg[k].mark != 0)
        {
            cnt++;
            k++;
        }
    }
    else if(c == 'I')
    {
        while(st[p].it[k].mark != 0)
        {
            cnt++;
            k++;
        }
    }
    return cnt;
}

void add_student(student *st, int *n)
{
    int current_num, ff = 0;
    st = realloc(st, (*n+1)*sizeof(student));
    printf("Enter the number(5 digits) of the student: ");
    scanf("%d", &st[*n].num_in_class);
    current_num = st[*n].num_in_class;
    for(int i = 0; i < *n; i++)
    {
        if(st[i].num_in_class == current_num)
        {
            ff = 1;
            printf("The student with that number is already in the system\n");
            break;
        }
    }
    if(!ff)
    {
        printf("Enter the first name of the student: ");
        scanf("%s", st[*n].f_name);
        printf("Enter the second name of the student: ");
        scanf("%s", st[*n].s_name);
        printf("Enter the third name of the student: ");
        scanf("%s", st[*n].t_name);
        st[*n].math[0].mark = 0;
        st[*n].bg[0].mark = 0;
        st[*n].it[0].mark = 0;
        (*n)++;
    }
}

void END(student *st, int n)
{
    FILE *fp_b;
    fp_b = fopen("student_b", "wb");
    if(fp_b == NULL)
    {
        perror("problem with opening b_file");
        exit(1);
    }
    for(int i = 0; i < n; i++)
    {
        if(fwrite(&st[i], sizeof(st[i]), 1, fp_b) != 1)
        {
            perror("problem with writing in b_file");
            fclose(fp_b);
            exit(1);
        }
    }
    fclose(fp_b);
}
