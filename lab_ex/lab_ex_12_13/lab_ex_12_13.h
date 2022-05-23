#ifndef LAB_EX_12_H_INCLUDED
#define LAB_EX_12_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#1
typedef struct Articals
{
    char name[21];
    char maker[21];
    double price;
    int quantity;
}Articals;

void information(Articals *articals, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Name: ");
        scanf("%s", articals[i].name);
        printf("Maker: ");
        scanf("%s", articals[i].maker);
        printf("Price: ");
        scanf("%lf", &articals[i].price);
        printf("Quantity: ");
        scanf("%d", &articals[i].quantity);
        printf("\n");
    }
}

float average_price(Articals *articals, int n)
{
    float average = 0;
    for(int i = 0; i < n; i++)
    {
        average += articals[i].price;
    }
    average /= n;
    return average;
}

void sorted_array(Articals *articals, int n)
{
    Articals artical;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(strcmp(articals[i].name, articals[j].name) > 0)
            {
                artical = articals[i];
                articals[i] = articals[j];
                articals[j] = artical;
            }
        }
    }
}

void displaying_array(Articals *articals, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Name: %s\n", articals[i].name);
        printf("Maker: %s\n", articals[i].maker);
        printf("Price: %.2lf\n", articals[i].price);
        printf("Name: %d\n", articals[i].quantity);
        printf("\n");
    }
}

//#2
typedef struct Name
{
    char *fName;
    char *sName;
    char *tName;
}Name;

typedef struct Students
{
  Name name;
  char *specialty;
  double grade;
  char gender;
  int age;
}Students;

void students_info(Students *students, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("First name: ");
        students[i].name.fName = (char *)malloc(sizeof(char)*20);
        scanf("%s", students[i].name.fName);
        printf("Second name: ");
        students[i].name.sName = (char *)malloc(sizeof(char)*20);
        scanf("%s", students[i].name.sName);
        printf("Third name: ");
        students[i].name.tName = (char *)malloc(sizeof(char)*20);
        scanf("%s", students[i].name.tName);
        printf("Specialty: ");
        students[i].specialty = (char *)malloc(sizeof(char)*30);
        scanf("%s", students[i].specialty);
        printf("Grade: ");
        scanf("%lf", &students[i].grade);
        fflush(stdin);
        printf("Gender(M/F): ");
        scanf("%c", &students[i].gender);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("\n");
    }
}

void display_student(Students st)
{
    printf("First name: %s\n", st.name.fName);
    printf("Second name: %s\n", st.name.sName);
    printf("Third name: %s\n", st.name.tName);
    printf("Specialty: %s\n", st.specialty);
    printf("Grade: %.2lf\n", st.grade);
    printf("Gender: %c\n", st.gender);
    printf("Age: %d\n\n", st.age);
}

void func_mark4(Students *students, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(students[i].grade < 4.50)
        {
            display_student(students[i]);
        }
    }
}

void func_mark6_25(Students *students, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(students[i].grade >= 5.50 && students[i].age < 25)
        {
            display_student(students[i]);
        }
    }
}

void bigger_grade(Students *students, int n)
{
    double grade_m = 0, grade_f = 0;
    for(int i = 0; i < n; i++)
    {
        if(students[i].gender == 'M')
        {
            grade_m += students[i].grade;
        }
        else if(students[i].gender == 'F')
        {
            grade_f += students[i].grade;
        }
    }
    if(grade_m > grade_f)
    {
        printf("Males have bigger grade!\n");
    }
    else if(grade_m < grade_f)
    {
        printf("Females have bigger grade!\n");
    }
    else
    {
        printf("Male and Female have equal grade!\n");
    }
}

//#3
typedef struct Telephon
{
    char *name;
    int code;
    char *number;
}Telephon;

void telephon_info(char *name, int *code, char *number)
{
    printf("Name: ");
    scanf("%s", name);
    printf("Code: ");
    scanf("%d", code);
    printf("Number: ");
    scanf("%s", number);
}

void telephon_display(Telephon telephon)
{
    printf("\nName: %s\n", telephon.name);
    printf("Code: %d\n", telephon.code);
    printf("Number: %s\n\n", telephon.number);
}

//#4
typedef struct Employee
{
    unsigned long ind_num;
    int hourly_payment;
    int hours_otr;
    float weekly_payment;
}Employee;

void employee_info(Employee *emp, int *n)
{
    for(int i = 0; i < (*n); i++)
    {
        printf("Identification number: ");
        scanf("%lu", &emp[i].ind_num);
        printf("Hourly payment: ");
        scanf("%d", &emp[i].hourly_payment);
        printf("Additional hours: ");
        scanf("%d", &emp[i].hours_otr);
        printf("\n");
    }
}

void weekly_paymnet(Employee *emp, int *n)
{
    for(int i = 0; i < (*n); i++)
    {
        emp[i].weekly_payment = 8 * 5 * emp[i].hourly_payment;
        if(emp[i].hours_otr >= 1)
        {
            emp[i].weekly_payment  += emp[i].hours_otr * (emp[i].hourly_payment + emp[i].hourly_payment * 150/100);
        }
        emp[i].weekly_payment -= emp[i].weekly_payment * 3.65/100;
    }
}

Employee *add_employee(Employee *employee, int *emp, FILE *fp_b)
{
    employee = (Employee *)realloc(employee, sizeof(Employee)*(*emp + 1));
    if(employee == NULL)
    {
        perror("Error realloc");
        exit(1);
    }
    printf("Identification number: ");
    scanf("%lu", &employee[*emp].ind_num);
    printf("Hourly payment: ");
    scanf("%d", &employee[*emp].hourly_payment);
    printf("Additional hours: ");
    scanf("%d", &employee[*emp].hours_otr);
    printf("\n");
    employee[*emp].weekly_payment = 8 * 5 * employee[*emp].hourly_payment;
    if(employee[*emp].hours_otr >= 1)
    {
        employee[*emp].weekly_payment  += employee[*emp].hours_otr * (employee[*emp].hourly_payment + employee[*emp].hourly_payment * 150/100);
    }
    employee[*emp].weekly_payment -= employee[*emp].weekly_payment * 3.65/100;
    if(fwrite(&employee[*emp], sizeof(employee[*emp]), 1, fp_b) != 1)
    {
        perror("Error writing");
        fclose(fp_b);
        exit(1);
    }
    (*emp)++;
    return employee;
}

#endif // LAB_EX_12_H_INCLUDED
